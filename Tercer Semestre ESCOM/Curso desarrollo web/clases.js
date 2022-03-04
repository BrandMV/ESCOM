class poligono{
    nombre;
    contador=100
    constructor( longitud ){
        this.longitud = longitud;
        this.nombre="Carlos";
    }

    prueba(){
        console.log("Esta es una prueba");
    }

    static saludar(){
        console.log("soy un poligono");
    }
}

class cuadrado extends poligono{
    constructor(lado){
        super(lado);
        this.lado=lado;

    }




}
var Cuadrado=new cuadrado(10);
console.log(Cuadrado.lado);

/*cuadrado.prueba();
poligono.saludar();
console.log(cuadrado.nombre);
console.log(cuadrado.contador);*/
