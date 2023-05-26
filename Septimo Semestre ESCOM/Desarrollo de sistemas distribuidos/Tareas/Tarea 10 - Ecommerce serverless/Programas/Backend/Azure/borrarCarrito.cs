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
using System.Collections;

namespace t10azf
{
    public static class borrarCarrito
    {
        class Error
        {
            public string mensaje;
            public Error(string mensaje)
            {
                this.mensaje = mensaje;
            }
        }
        class ArticuloCarrito
        {
            public int IdProducto;
            public int Cantidad;
        }
        [FunctionName("borrarCarrito")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous, "post")] HttpRequest req,
            ILogger log)
        {
            try
            {
                string requestBody = await new StreamReader(req.Body).ReadToEndAsync();


                string Server = Environment.GetEnvironmentVariable("Server");
                string UserID = Environment.GetEnvironmentVariable("UserID");
                string Password = Environment.GetEnvironmentVariable("Password");
                string Database = Environment.GetEnvironmentVariable("Database");

                string cs = "Server=" + Server + ";UserID=" + UserID + ";Password=" + Password + ";" + "Database=" + Database + ";SslMode=Preferred;";

                var conexion = new MySqlConnection(cs);
                conexion.Open();
                var conexion2 = new MySqlConnection(cs);
                conexion2.Open();
                try
                {
                    var cmd = new MySqlCommand();
                    cmd.Connection = conexion;
                    cmd.CommandText = "SELECT a.id_articulo, b.cantidad FROM articulos a JOIN carrito_compra b ON a.id_articulo=b.id_articulo";
                    MySqlDataReader r = cmd.ExecuteReader();
                    try
                    {
                        ArrayList articulosCarrito = new ArrayList();
                        while (r.Read())
                        {
                            ArticuloCarrito ar = new ArticuloCarrito();
                            ar.IdProducto = r.GetInt32(0);
                            ar.Cantidad = r.GetInt32(1);
                            articulosCarrito.Add(ar);
                        }
                        MySqlTransaction transaccion = conexion2.BeginTransaction();
                        try
                        {
                            var cmd2 = new MySqlCommand();
                            cmd2.Connection = conexion2;
                            cmd2.Transaction = transaccion;
                            cmd2.CommandText = "DELETE FROM carrito_compra";
                            cmd2.ExecuteNonQuery();

                            foreach (ArticuloCarrito ar in articulosCarrito)
                            {
                                var cmd3 = new MySqlCommand();
                                cmd3.Connection = conexion2;
                                cmd3.Transaction = transaccion;
                                cmd3.CommandText = "UPDATE articulos SET cantidad=cantidad+@cantidadArticulo WHERE id_Articulo=@idArticulo";
                                cmd3.Parameters.AddWithValue("@cantidadArticulo", ar.Cantidad);
                                cmd3.Parameters.AddWithValue("@idArticulo", ar.IdProducto);
                                cmd3.ExecuteNonQuery();
                            }

                            transaccion.Commit();
                            return new OkObjectResult("Carrito borrado");
                        }
                        catch (Exception e)
                        {
                            transaccion.Rollback();
                            throw new Exception(e.Message);
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
