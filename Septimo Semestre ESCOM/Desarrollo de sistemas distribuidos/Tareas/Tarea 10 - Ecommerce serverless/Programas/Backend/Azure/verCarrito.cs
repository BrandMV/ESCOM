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
    public static class verCarrito
    {
        class Articulo
        {
            public int Id;
            public string Nombre;
            public string Descripcion;
            public Decimal? Precio;
            public int? Cantidad;
            public string Foto;
        }
        class Error
        {
            public string mensaje;
            public Error(string mensaje)
            {
                this.mensaje = mensaje;
            }
        }
        [FunctionName("verCarrito")]
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
                try
                {
                    var cmd = new MySqlCommand();
                    cmd.Connection = conexion;
                    cmd.CommandText = "SELECT a.id_articulo, a.nombre, a.precio, a.foto, length(a.foto), b.cantidad FROM articulos a JOIN carrito_compra b ON a.id_articulo=b.id_articulo";
                    MySqlDataReader r = cmd.ExecuteReader();
                    ArrayList articulos = new ArrayList();
                    try
                    {
                        while (r.Read())
                        {
                            Articulo ar = new Articulo();
                            ar.Id = r.GetInt32(0);
                            ar.Nombre = r.GetString(1);
                            ar.Precio = r.GetDecimal(2);
                            var longitud = r.GetInt32(4);
                            byte[] foto = new byte[longitud];
                            r.GetBytes(3, 0, foto, 0, longitud);
                            ar.Foto = Convert.ToBase64String(foto);
                            ar.Cantidad = r.GetInt32(5);
                            articulos.Add(ar);
                        }

                        if (articulos.Count == 0 || articulos == null)
                        {
                            throw new Exception("No tienes articulos en tu carrito");
                        }
                        return new ContentResult { Content = JsonConvert.SerializeObject(articulos), ContentType = "application/json" };
                    }
                    finally
                    {
                        r.Close();
                    }
                }
                finally
                {
                    conexion.Close();
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
