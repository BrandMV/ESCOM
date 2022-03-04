//sumatoria
var sumatoria= function(...args){
    var result=0;
    for(numero of args){
        result+=numero;
    }
    return result;
}

const nombre="Pedro"

exports.sumatoria=sumatoria;
exports.nombre=nombre;