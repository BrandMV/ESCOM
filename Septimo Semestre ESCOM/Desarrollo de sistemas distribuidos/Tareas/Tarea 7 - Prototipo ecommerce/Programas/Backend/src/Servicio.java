import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;


import com.google.gson.*;

import java.sql.*;
import java.util.ArrayList;

public class Servicio {
    static DataSource pool = null;
    static{
        try{
            Context ctx = new InitialContext();
            pool = (DataSource) ctx.lookup("java:comp/env/jdbc/datasource_Servicio");
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    static Gson j = new GsonBuilder().registerTypeAdapter(byte[].class,new AdaptadorGsonBase64()).setDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS").create();

    @POST
    @Path("altaArticulo")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response altaArticulo(String json) throws Exception{
        ParamAltaArticulo p = (ParamAltaArticulo) j.fromJson(json, ParamAltaArticulo.class);
        Articulo articulo = p.articulo;

        Connection conexion = pool.getConnection();
        /// Ningun campo del articulo puede ser nulo
        if(articulo.Nombre == null || articulo.Nombre.equals(""))
            return Response.status(400).entity(j.toJson(new Error("Se debe ingresar un nombre para el artículo"))).build();

        if(articulo.Descripcion == null || articulo.Descripcion.equals(""))
            return Response.status(400).entity(j.toJson(new Error("Se debe ingresar una descripción para el artículo"))).build();

        if(articulo.Precio == null)
            return Response.status(400).entity(j.toJson(new Error("Se debe ingresar un precio válido"))).build();

        if(articulo.Cantidad == null)
            return Response.status(400).entity(j.toJson(new Error("Se debe ingresar una cantidad en almacén válida"))).build();

        if(articulo.Foto == null)
            return Response.status(400).entity(j.toJson(new Error("Se debe ingresar una foto para el artículo"))).build();

        try{
            conexion.setAutoCommit(false);

            PreparedStatement stmt1 = conexion.prepareStatement("INSERT INTO articulos (id_articulo, nombre, descripcion, precio, cantidad, foto) VALUES (0, ?, ?, ?, ?, ?)");
            try{
                stmt1.setString(1, articulo.Nombre);
                stmt1.setString(2, articulo.Descripcion);
                stmt1.setBigDecimal(3, articulo.Precio);
                stmt1.setInt(4, articulo.Cantidad);
                stmt1.setBytes(5, articulo.Foto);
                stmt1.executeUpdate();
            }finally {
                stmt1.close();
            }
            conexion.commit();
        }catch (Exception e){
            conexion.rollback();
            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
        }finally {
            conexion.setAutoCommit(true);
            conexion.close();
        }
        return Response.ok().build();
    }

    @POST
    @Path("buscarArticulo")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response buscarArticulo(String json) throws Exception{
        ParamBuscaArticulo p = (ParamBuscaArticulo) j.fromJson(json, ParamBuscaArticulo.class);
        String palabraClave = p.PalabraClave;

        Connection conexion = pool.getConnection();
        try{
            PreparedStatement stmt1 = conexion.prepareStatement("SELECT id_articulo, nombre, descripcion, precio, cantidad, foto FROM articulos WHERE nombre LIKE CONCAT('%', ?, '%') OR descripcion LIKE CONCAT('%', ?, '%')");
            try{
                stmt1.setString(1, palabraClave);
                stmt1.setString(2, palabraClave);

                ResultSet rs = stmt1.executeQuery();
                try{
                    ArrayList<Articulo> articulosEncontrados = new ArrayList<>();
                    while(rs.next()){
                        Articulo r = new Articulo();
                        r.Id = rs.getInt(1);
                        r.Nombre = rs.getString(2);
                        r.Descripcion = rs.getString(3);
                        r.Precio = rs.getBigDecimal(4);
                        r.Cantidad = rs.getInt(5);
                        r.Foto = rs.getBytes(6);
                        articulosEncontrados.add(r);
                    }
                    if(articulosEncontrados.size() == 0 && articulosEncontrados == null)
                        return Response.status(400).entity(j.toJson(new Error("No se encontraron artículos"))).build();

                    return Response.ok().entity(j.toJson(articulosEncontrados)).build();
                }finally {
                    rs.close();
                }
            }finally {
                stmt1.close();
            }
        }catch (Exception e){
            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
        }finally {
            conexion.close();
        }
    }

    @POST
    @Path("agregarCarrito")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response agregarCarrito(String json) throws Exception{
        ParamAgregarCarrito pCarrito = (ParamAgregarCarrito) j.fromJson(json, ParamAgregarCarrito.class);
        Integer cantidad = pCarrito.Cantidad;
        String nombreArticulo = pCarrito.Nombre;

        Connection conexion = pool.getConnection();
        try{
            PreparedStatement stmt1 = conexion.prepareStatement("SELECT id_articulo, cantidad FROM articulos WHERE nombre=?);
            try{
                stmt1.setString(1, nombreArticulo);
                ResultSet rs = stmt1.executeQuery();
                try{
                    if(rs.next()){
                        /// Empezando con la transacción
                        conexion.setAutoCommit(false);
                        try{
                            Integer idArticulo = rs.getInt(1);
                            Integer cantidadDisponible = rs.getInt(2);
                            if(cantidad <= cantidadDisponible){
                                /// Insertando producto en carrito
                                PreparedStatement stmt2 = conexion.prepareStatement("INSERT INTO carrito_compra(id_articulo, cantidad) VALUES (?, ?)");
                                try{
                                    stmt2.setInt(1, idArticulo);
                                    stmt2.setInt(2, cantidad);
                                    stmt2.executeUpdate();
                                }finally {
                                    stmt2.close();
                                }
                                /// Actualizando tabla de articulos
                                PreparedStatement stmt3 = conexion.prepareStatement("UPDATE articulos SET cantidad=? WHERE id_articulo=?");
                                try{
                                    Integer nuevaCantidad = cantidadDisponible - cantidad;
                                    stmt3.setInt(1, nuevaCantidad);
                                    stmt3.setInt(2, idArticulo);
                                    stmt3.executeUpdate();
                                }finally {
                                    stmt3.close();
                                }
                            }
                            conexion.commit();
                        }catch (Exception e){
                            conexion.rollback();
                            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
                        }finally {
                            conexion.setAutoCommit(true);
                        }
                    }else
                        return Response.status(400).entity(j.toJson(new Error("Error con el producto"))).build();
                }finally {
                    rs.close();
                }
            }finally {
                stmt1.close();
            }
        }catch (Exception e){
            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
        }finally {
            conexion.close();
        }

        return Response.ok().build();
    }

    @POST
    @Path("eliminarArticuloCarrito")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response eliminarArticuloCarrito(String json) throws Exception{
        ParamEliminarArticuloCarrito p = (ParamAltaArticulo) j.fromJson(json, ParamEliminarArticuloCarrito.class);
        Integer idArticulo = p.Id;

        Connection conexion = pool.getConnection();
        try{
            PreparedStatement stmt1 = conexion.prepareStatement("SELECT id_articulo, cantidad FROM carrito_compra WHERE id_articulo=?");
            try{
                stmt1.setInt(1, idArticulo);
                ResultSet rs = stmt1.executeQuery();
                try{
                    if(rs.next()){
                        /// Iniciando transacción
                        conexion.setAutoCommit(false);
                        try{
                            Integer cantidad = rs.getInt(2);
                            /// Borrando arituclo del carrito
                            PreparedStatement stmt2 = conexion.prepareStatement("DELETE FROM carrito_compra WHERE id_articulo=?");
                            try{
                                stmt2.setInt(1, idArticulo);
                                stmt2.executeUpdate();
                            }finally {
                                stmt2.close();
                            }
                            PreparedStatement stmt3 = conexion.prepareStatement("UPDATE articulos SET cantidad=cantidad+? WHERE id_articulo=?");
                            try{
                                stmt3.setInt(1, cantidad);
                                stmt3.setInt(2, idArticulo);
                                stmt3.executeUpdate();
                            }finally {
                                stmt3.close();
                            }
                            conexion.commit();
                        }catch (Exception e){
                            conexion.rollback();
                            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
                        }finally {
                            conexion.setAutoCommit(true);
                        }
                    }else{
                        return Response.status(400).entity(j.toJson(new Error("No fue posible eliminar el artículo"))).build();
                    }
                }finally {
                    rs.close();
                }
            }finally {
                stmt1.close();
            }
        }catch (Exception e){
            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
        }finally {
            conexion.close();
        }

        return Response.ok().build();
    }

    @POST
    @Path("borrarCarrito")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response borrarCarrito() throws Exception{
        Connection conexion = pool.getConnection();
        try{
            PreparedStatement stmt1 = conexion.prepareStatement("SELECT a.id_articulo, b.cantidad FROM articulos a JOIN carrito_compra b ON a.id_articulo=b.id_articulo");
            try{
                ResultSet rs = stmt1.executeQuery();
                ArrayList<ArticuloCarrito> articulosCarrito = new ArrayList<>();
                while(rs.next()){
                    ArticuloCarrito ar = new ArticuloCarrito();
                    ar.IdProducto = rs.getInt(1);
                    ar.Cantidad = rs.getInt(2);
                    articulosCarrito.add(ar);
                }
                /// Iniciando transaccion
                conexion.setAutoCommit(false);
                try{
                    /// ELiminando el carrito de compra
                    PreparedStatement stmt2 = conexion.prepareStatement("DELETE FROM carrito_compra");
                    try{
                        stmt2.executeUpdate();
                    }finally {
                        stmt2.close();
                    }
                    for(ArticuloCarrito articulo: articulosCarrito){
                        PreparedStatement stmt3 = conexion.prepareStatement("UPDATE articulos SET cantidad=cantidad+? WHERE id_articulo=?");
                        try{
                            stmt3.setInt(1, articulo.Cantidad);
                            stmt3.setInt(2, articulo.IdProducto);
                            stmt3.executeUpdate();
                        }finally {
                            stmt3.close();
                        }
                        conexion.commit();
                    }
                }catch (Exception e){
                    conexion.rollback();
                    return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
                }finally {
                    conexion.setAutoCommit(true);
                }
            }finally {
                stmt1.close();
            }
        }catch (Exception e){
            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
        }finally {
            conexion.close();
        }

        return Response.ok().build();
    }

    @POST
    @Path("verCarrito")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response verCarrito() throws Exception{
        Connection conexion = pool.getConnection();
        try{
            PreparedStatement stmt1 = conexion.prepareStatement("SELECT a.id_articulo, a.nombre, a.precio, a.foto, b.cantidad FROM articulos a JOIN carrito_compra b ON a.id_articulo=b.id_articulo");
            try{
                ResultSet rs = stmt1.executeQuery();
                ArrayList<Articulo> articulos = new ArrayList<>();
                while(rs.next()){
                    Articulo ar = new Articulo();
                    ar.Id = rs.getInt(1);
                    ar.Nombre = rs.getString(2);
                    ar.Descripcion = "";
                    ar.Precio = rs.getBigDecimal(3);
                    ar.Foto = rs.getBytes(4);
                    ar.Cantidad = rs.getInt(5);
                    articulos.add(ar);
                }
                rs.close();
                return Response.ok().entity(j.toJson(articulos)).build();
            }catch (Exception e){
                return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
            }finally {
                stmt1.close();
            }
        }catch (Exception e){
            return Response.status(400).entity(j.toJson(new Error(e.getMessage()))).build();
        }finally {
            conexion.close();
        }
    }

}
