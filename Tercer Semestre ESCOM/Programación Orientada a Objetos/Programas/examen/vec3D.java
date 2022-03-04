/*
ALUMNO: Meza Vargas Brandon David
GRUPO: 2CM1
Problema: 2

TAD

2.-Codificar en Java un tipo de dato abstracto (TAD) para vectores tridimensionales Vec3D


Si v1 = (x1, y1, z1) y v1 = (x2, y2, z2)

entonces


suma v1+v2=(x1+x2, y1+y2, z1+z2)

resta v1-v2=(x1-x2, y1-y2, z1-z2)

producto punto v1.v2= x1*x2 + y1*y2 + z1*z2 resultado escalar


Si v = (x, y, z) entonces modulo(v) = sqrt(x*x + y*y+z*z) = sqrt (productoPunto(v.v))


v1 = v2 si x1 = x2 y y1 = y2 y z1 = z2


Codificar el constructor


Este TAD debe tener las siguientes operaciones: sumar, restar, productoPunto, modulo, esIgual, imprimir

Modelado:
---------------
vec3D
---------------
x
y
z
---------------
sum(...)
res(...)
pPunto(...)
mod(...)
esIgual(...)
imprimir(...)
---------------
*/

package examen;

public class vec3D {
    Double x,y,z;

    public vec3D(Double x, Double y, Double z){
        this.x=x;
        this.y=y;
        this.z=z;
    }

    public vec3D sum(vec3D v){
        return new vec3D(x + v.x, y + v.y, z + v.z);
    }

    public vec3D res(vec3D v){
        return new vec3D(x - v.x, y - v.y, z - v.z);
    }

    public Double  pPunto(vec3D v){
        return ((x * v.x) + (y * v.y) + (z * v.z));
    }

    public Double mod(vec3D v){
        return Math.sqrt(pPunto(v));
    }

    public boolean esIgual(vec3D v){
        return (v.x == this.x) & (v.y == this.y) & (v.z == this.z);
    }

    public void imprimir(){
        System.out.println("(" + x + ", " +y+ ", " + z +")");
    }

    public static void main(String[] args) {
        vec3D v1,v2,v3,v4;
        Double res,m;
        Boolean b;
        v1 = new vec3D(5.0, 3.0, 7.0);
        v2 = new vec3D(5.0, 10.0, 7.0);

        System.out.println("¿Es igual?: ");
        b=v1.esIgual(v2);
        System.out.println(b);

        System.out.println("Suma: ");
        v3=v1.sum(v2);
        v3.imprimir();

        System.out.println("Resta: ");
        v4=v1.res(v2);
        v4.imprimir();
        System.out.println("Producto Punto: ");
        res=v1.pPunto(v2);
        System.out.println(res);

        System.out.println("Modulo: ");
        m=v1.mod(v2);
        System.out.println(m);
     
    }

}
