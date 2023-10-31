using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;

namespace t10azf
{
    public static class Get
    {
        [FunctionName("Get")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous, "get")] HttpRequest req,
            ILogger log)
        {
            try
            {
                string path = (string)req.Query["nombre"];

                string home = Environment.GetEnvironmentVariable("HOME");

                try
                {
                    byte[] contenido = File.ReadAllBytes(home + "/data" + path);
                    string nombre = Path.GetFileName(path);
                    string tipo_mime = MimeMapping.GetMimeMapping(path);
                    DateTime fecha_modificacion = File.GetLastWriteTime(home + "/data" + path);

                    return new FileContentResult(contenido, tipo_mime)
                    {
                        LastModified = fecha_modificacion
                    };
                }
                catch (FileNotFoundException)
                {
                    return new NotFoundResult();
                }
            }
            catch (Exception e)
            {
                return new BadRequestObjectResult(e.Message);
            }

        }
    }
}
