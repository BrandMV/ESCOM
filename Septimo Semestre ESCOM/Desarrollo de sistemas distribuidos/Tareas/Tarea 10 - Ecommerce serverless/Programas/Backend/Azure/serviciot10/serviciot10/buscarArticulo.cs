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

namespace serviciot10
{
    public static class buscarArticulo
    {
        class ArticuloBusqueda
        {
            public int Id;
            public string Nombre;
            public string Descripcion;
            public Decimal Precio;
            public string Foto;
        }
        class ParamBuscaArticulo
        {
            public string PalabraClave;
        }
        class Error
        {
            public string mensaje;
            public Error(string mensaje)
            {
                this.mensaje = mensaje;
            }
        }
        [FunctionName("buscarArticulo")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous,"post")] HttpRequest req,
            ILogger log)
        {
            try
            {
                string requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                ParamBuscaArticulo data = JsonConvert.DeserializeObject<ParamBuscaArticulo>(requestBody);
                string palabraClave= data.PalabraClave;

                string Server = Environment.GetEnvironmentVariable("Server");
                string UserID = Environment.GetEnvironmentVariable("UserID");
                string Password = Environment.GetEnvironmentVariable("Password");
                string Database = Environment.GetEnvironmentVariable("Database");

                string cs = "Server=" + Server + ";UserID=" + UserID + ";Password=" + Password + ";" + "Database=" + ";SslMode=Preferred;";
                var conexion = new MySqlConnection(cs);
                conexion.Open();

                try
                {
                    var cmd = new MySqlCommand("SELECT id_articulo, nombre, descripcion, precio, foto, length(foto) FROM articulos WHERE nombre LIKE CONCAT('%', @palabra, '%') OR descripcion LIKE CONCAT('%', @palabra, '%')");
                    cmd.Connection = conexion;
                    cmd.Parameters.AddWithValue("@palabra", palabraClave);
                    MySqlDataReader r = cmd.ExecuteReader();

                    try
                    {
                        ArrayList articulosEncontrados = new ArrayList();
                        while (r.NextResult())
                        {
                            ArticuloBusqueda rb = new ArticuloBusqueda();
                            rb.Id = r.GetInt32(0);
                            rb.Nombre = r.GetString(1);
                            rb.Descripcion = r.GetString(2);
                            rb.Precio = r.GetDecimal(3);
                            var longitud = r.GetInt32(5);
                            byte[] foto = new byte[longitud];
                            r.GetBytes(4, 0, foto, 0, longitud);
                            rb.Foto = Convert.ToBase64String(foto);

                            articulosEncontrados.Add(rb);
                        }
                        if(articulosEncontrados.Count == 0 || articulosEncontrados == null)
                        {
                            throw new Exception("No se encontraron articulos");
                        }

                        return new ContentResult { Content = JsonConvert.SerializeObject(articulosEncontrados), ContentType = "application/json" };
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
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
                return new BadRequestObjectResult(JsonConvert.SerializeObject(new Error(e.Message)));
            }
        }
    }
}
