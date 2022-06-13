//mapa
/*
let telefonos = {
    Carlos: 55123,
    Mauricio: 12345,
    Diego: 1999
};

console.log(telefonos["Carlos"]);

console.log(`Mauricio esta en el mapeao = ${"Mauriicio" in telefonos}`);

console.log("toString esta en el mapeo= " + ( "toString" in telefonos));


let telefonos = new Map();
telefonos.set("Mauricio", 12345)
telefonos.set("Carlos", 5567)

console.log("El telefono de Carlos es: " + telefono.get("Carlos"));

console.log(`Esta el telefono de Mauricio? ${telefonos.has("Mauricio")}`);

console.log(telefonos.has("toString"));


var objeto = {
    nombre: "Carlos",
    telefono: 12345
};

//polimorfismo es cambiar los metodos que estan definidos

Object.prototype.toString = function(){
    return `El nombre es: ${this.nombre} y su telefono es ${this.telefono}`
};

console.log(String(objeto));


let objeto1 ={

};
class objeto2{
    constructor(){

    }
}

var objeto3 = function(a,b){
    this.a=a
    this.b=b
}

var instancia_obj3 = new objeto3(4,7);

console.log(instancia_obj3.a);
console.log(instancia_obj3.b);
*/
/**
 * Esta funcion es para tal
 * @argument
 * @returns
 */

function prueba(a,b){
    //"use strict"; casi no se usa
    for(i = 0; i<10; i++){
        console.log(a,b);
        console.log(i);
    }
    console.log("Salto el for");
}

prueba();