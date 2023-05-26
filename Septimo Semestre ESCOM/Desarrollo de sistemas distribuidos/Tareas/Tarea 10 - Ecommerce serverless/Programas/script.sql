
CREATE TABLE articulos(
  id_articulo integer AUTO_INCREMENT PRIMARY KEY,
  nombre varchar(50) not null,
  descripcion varchar(100) not null,
  precio decimal not null,
  cantidad integer not null,
  foto longblob not null);
 create TABLE carrito_compra(
   id_articulo integer not null,
   cantidad integer not null);
 alter table carrito_compra add FOREIGN KEY (id_articulo) REFERENCES articulos(id_articulo);