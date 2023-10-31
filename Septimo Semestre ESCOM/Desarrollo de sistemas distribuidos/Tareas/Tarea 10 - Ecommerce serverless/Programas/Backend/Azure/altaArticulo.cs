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
    public static class altaArticulo
    {
        class Articulo
        {
            public string Nombre;
            public string Descripcion;
            public Decimal? Precio;
            public int? Cantidad;
            public string Foto;
        }
        class ParamAltaArticulo
        {
            public Articulo articulo;
        }
        class Error
        {
            public string mensaje;
            public Error(string mensaje)
            {
                this.mensaje = mensaje;
            }
        }
        [FunctionName("altaArticulo")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous, "post")] HttpRequest req,
            ILogger log)
        {
            try
            {
                string requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                ParamAltaArticulo data = JsonConvert.DeserializeObject<ParamAltaArticulo>(requestBody);
                Articulo articulo = data.articulo;

                if (articulo.Nombre == null || articulo.Nombre == "") throw new Exception("Se debe ingresar un nombre para el articulo");
                if (articulo.Descripcion == null || articulo.Descripcion == "") throw new Exception("Se debe ingresar una descripción para el articulo");
                if (articulo.Precio == null) throw new Exception("Se debe ingresar un precio válido");
                if (articulo.Cantidad == null) throw new Exception("Se debe ingresar una cantidad valida");
                if (articulo.Foto == null) throw new Exception("Se debe ingresar una foto para el articulo");

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
                    cmd.CommandText = "INSERT INTO articulos(id_articulo, nombre, descripcion, precio, cantidad, foto) VALUES (0, @nombre, @descripcion, @precio, @cantidad, @foto)";
                    cmd.Parameters.AddWithValue("@nombre", articulo.Nombre);
                    cmd.Parameters.AddWithValue("@descripcion", articulo.Descripcion);
                    cmd.Parameters.AddWithValue("precio", articulo.Precio);
                    cmd.Parameters.AddWithValue("@cantidad", articulo.Cantidad);
                    cmd.Parameters.AddWithValue("@foto", Convert.FromBase64String(articulo.Foto));
                    cmd.ExecuteNonQuery();
                    return new OkObjectResult("Articulo insertado");
                }
                catch (Exception e)
                {
                    throw new Exception(e.Message);
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
