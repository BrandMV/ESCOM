let prueba = {
    a: 200,
    b: 300,
    c: 1000
};

//console.log(prueba.propertyIsEnumerable('toString')); no numerable
console.log(prueba.propertyIsEnumerable('a'));

for (let r in prueba){
    console.log(r);
}

console.log(Object.keys(prueba)); //el valor que no nos saque significa que no es enumarable
console.log(Object.getOwnPropertyNames(prueba));
console.log(Reflect.ownKeys(prueba));

//para pasar propiedades de un objeto a otro
let target = {x:1}, source = {y:2,z:3}, source_2={custom:"hola",x:10}
//Object.assign(target,source,source_2)

//console.log(target);

let resultado={...source,...source_2,...target} //Con objetos que no tengan las mismas propiedades
console.log(resultado);

target["computadora"]="Hola";