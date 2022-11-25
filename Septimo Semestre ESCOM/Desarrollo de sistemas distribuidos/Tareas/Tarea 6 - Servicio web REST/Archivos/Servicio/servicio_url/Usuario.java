/*
  Carlos Pineda Guerrero, noviembre 2022
*/

package servicio_url;

import java.sql.Timestamp;
import com.google.gson.*;

public class Usuario
{
  String email;
  String nombre;
  String apellido_paterno;
  String apellido_materno;
  Timestamp fecha_nacimiento;
  Long telefono;
  String genero;
  byte[] foto;

  // @FormParam tuiliza el metodo valueOf para convertir l string json al objeto de tipo Usuario
  // @FormParam solo puede utilizarse cuando el método web consume application/x-www-form-urlencoded 

  public static Usuario valueOf(String json) throws Exception
  {
    Gson j = new GsonBuilder().registerTypeAdapter(byte[].class,new AdaptadorGsonBase64()).setDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS").create();
    return (Usuario)j.fromJson(json,Usuario.class);
  }
}
