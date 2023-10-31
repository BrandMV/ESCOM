using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using MySql.Data.MySqlClient;


namespace t10azf
{
    public static class eliminarArticuloCarrito
    {
        class ParamEliminarArticuloCarrito
        {
            public int Id;
        }
        class Error
        {
            public string mensaje;
            public Error(string mensaje)
            {
                this.mensaje = mensaje;
            }
        }
        [FunctionName("eliminarArticuloCarrito")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous, "post")] HttpRequest req,
            ILogger log)
        {
            try
            {
                string requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                ParamEliminarArticuloCarrito data = JsonConvert.DeserializeObject<ParamEliminarArticuloCarrito>(requestBody);
                int idArticulo = data.Id;

                string Server = Environment.GetEnvironmentVariable("Server");
                string UserID = Environment.GetEnvironmentVariable("UserID");
                string Password = Environment.GetEnvironmentVariable("Password");
                string Database = Environment.GetEnvironmentVariable("Database");

                string cs = "Server=" + Server + ";UserID=" + UserID + ";Password=" + Password + ";" + "Database="+ Database + ";SslMode=Preferred;";
                var conexion = new MySqlConnection(cs);
                conexion.Open();
                var conexion2 = new MySqlConnection(cs);
                conexion2.Open();

                try
                {
                    var cmd = new MySqlCommand();
                    cmd.Connection = conexion;
                    cmd.CommandText = "SELECT id_articulo, cantidad FROM carrito_compra WHERE id_articulo=@idArticulo";
                    cmd.Parameters.AddWithValue("@idArticulo", idArticulo);
                    MySqlDataReader r = cmd.ExecuteReader();
                    try
                    {
                        if (r.Read())
                        {
                            /// Iniciando transaccion
                            MySqlTransaction transaccion = conexion2.BeginTransaction();
                            try
                            {
                                int cantidad = r.GetInt32(1);
                                /// Borrando articulo del carrito
                                var cmd2 = new MySqlCommand();
                                cmd2.Connection = conexion2;
                                cmd2.Transaction = transaccion;
                                cmd2.CommandText = "DELETE FROM carrito_compra WHERE id_articulo=@idArticulo";
                                cmd2.Parameters.AddWithValue("@idArticulo", idArticulo);
                                cmd2.ExecuteNonQuery();

                                var cmd3 = new MySqlCommand();
                                cmd3.Connection = conexion2;
                                cmd3.Transaction = transaccion;
                                cmd3.CommandText = "UPDATE articulos SET cantidad=cantidad+@cantidadBorrada WHERE id_articulo=@idArticulo";
                                cmd3.Parameters.AddWithValue("@cantidadBorrada", cantidad);
                                cmd3.Parameters.AddWithValue("@idArticulo", idArticulo);
                                cmd3.ExecuteNonQuery();

                                transaccion.Commit();
                                return new OkObjectResult("Articulo borrado del carrito");
                            }
                            catch (Exception e)
                            {
                                transaccion.Rollback();
                                throw new Exception(e.Message);
                            }
                        }
                        else
                        {
                            throw new Exception("No se pudo eliminar el articulo");
                        }
                    }
                    finally
                    {
                        r.Close();
                    }
                }
                finally
                {
                    conexion.Close();
                    conexion2.Close();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return new BadRequestObjectResult(JsonConvert.SerializeObject(new Error(e.Message)));
            }
        }
    }
}
