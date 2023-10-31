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
    public static class agregarCarrito
    {
        class ParamAgregarCarrito
        {
            public int Id;
            public int Cantidad;
        }
        class Error
        {
            public string mensaje;
            public Error(string mensaje)
            {
                this.mensaje = mensaje;
            }
        }
        [FunctionName("agregarCarrito")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous, "post")] HttpRequest req,
            ILogger log)
        {
            try
            {
                string requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                ParamAgregarCarrito data = JsonConvert.DeserializeObject<ParamAgregarCarrito>(requestBody);
                int cantidad = data.Cantidad;
                int idArticuloParam = data.Id;

                string Server = Environment.GetEnvironmentVariable("Server");
                string UserID = Environment.GetEnvironmentVariable("UserID");
                string Password = Environment.GetEnvironmentVariable("Password");
                string Database = Environment.GetEnvironmentVariable("Database");

                string cs = "Server=" + Server + ";UserID=" + UserID + ";Password=" + Password + ";" + "Database=" + Database + ";SslMode=Preferred;";

                var conexion = new MySqlConnection(cs);
                var conexion2 = new MySqlConnection(cs);
                conexion.Open();
                conexion2.Open();

                try
                {
                    var cmd = new MySqlCommand("SELECT id_articulo, cantidad FROM articulos WHERE id_articulo=@idArticulo");
                    cmd.Connection = conexion;
                    cmd.Parameters.AddWithValue("@idArticulo", idArticuloParam);
                    MySqlDataReader r = cmd.ExecuteReader();
                    try
                    {
                        if (r.Read())
                        {
                            MySqlTransaction transaccion = conexion2.BeginTransaction();
                            try
                            {
                                int idArticulo = r.GetInt32(0);
                                int cantidadDisponible = r.GetInt32(1);
                                if (cantidad <= cantidadDisponible)
                                {
                                    /// Insertando producto en carrito
                                    var cmd2 = new MySqlCommand();
                                    cmd2.Connection = conexion2;
                                    cmd2.Transaction = transaccion;
                                    cmd2.CommandText = "INSERT INTO carrito_compra(id_articulo, cantidad) VALUES (@idArticulo, @cantidad)";
                                    cmd2.Parameters.AddWithValue("@idArticulo", idArticulo);
                                    cmd2.Parameters.AddWithValue("@cantidad", cantidad);
                                    cmd2.ExecuteNonQuery();

                                    var cmd3 = new MySqlCommand();
                                    cmd3.Connection = conexion2;
                                    cmd3.Transaction = transaccion;
                                    cmd3.CommandText = "UPDATE articulos SET cantidad=@nuevaCantidad WHERE id_articulo=@idArticulo";
                                    int nuevaCantidad = cantidadDisponible - cantidad;
                                    cmd3.Parameters.AddWithValue("@nuevaCantidad", nuevaCantidad);
                                    cmd3.Parameters.AddWithValue("@idArticulo", idArticulo);
                                    cmd3.ExecuteNonQuery();
                                }
                                else
                                {
                                    throw new Exception(String.Format("Cantidad disponible de articulos: {0}", cantidadDisponible));
                                }

                            }
                            catch (Exception e)
                            {
                                transaccion.Rollback();
                                throw new Exception(e.Message);
                            }
                            transaccion.Commit();
                            return new OkObjectResult("Articulo agregado a carrito");
                        }
                        else
                        {
                            throw new Exception("Error con el producto");
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
