function duplicar (valor){
    return valor*2;
}

//funciones flecha arrow function muyy usada

const dup = (valor) => { //Creamos una funcion anonima y la mandamos a una variable
    return valor * 2;
}

const dup2= valor => valor*2; //hacer lo de arriba, solo cuando retornamos algo. Podemos omitir los parentesis si nuestro parametro es uno

dup(1);
dup(3);
dup2(3);

//destructuring
const arr = ["Brandon", 19];
const [nombre, edad] = arr;

//objetos

const obj1={
    x=1,
    y=2
}

const add = ({x, y}) => x+y; //object destructuring
add(obj1)
//? para saber si existe un valor en un objeto

const pepe={edad: 19, nombre:"pepe"};
export {dup2, pepe} //hasta abajo ponemos lo que queremos compartir, la primera linea del otro archivo decimo que queremos importar

//== comparacion relajada 1=="1" - true y con === comparacion estricta 1=="1" - false
//siempre usar === a menos que hagas ==null

//DOM - Document Object Model

//Closures
const createCounter=()=> {
    let count=0
    return () =>{
        const current = count
        count+=1
        return current
    }

}

const c= createCounter()
console.log(c());
console.log(c());
console.log(c());
//funciones son de primera clase
//no side effects: si tu funcion es suma solamente suma
//Funcion pura: si le paso los
/*
React no es un framework, es una libreíra de JavaScript de código abierto, creada y mantenida por Facebook
Permite crear interfaces de usuario y aplicaciones en la web (y movil) usando programación reactiva(ejecuta esto cuando pasa esto) y funcional (usar funciones)
  
Framework: forma de porgramar modificando el lenguaje original
Libreria: Conjunto de codigo, hojas de javascript ya programadas listas para usar, no modifican el lenguaje

*/

const nums= [1,2,3,4,5,121]

console.log(nums.filter(x => x< 10));

const names =[

    {name: "oscar", edad:22},
    {name: "pedro", edad:21}

]
const edited = names.filter(({edad})=>edad >23).map((person) => {
    person.name.toUpperCase();

    return person;
});
console.log(edited);