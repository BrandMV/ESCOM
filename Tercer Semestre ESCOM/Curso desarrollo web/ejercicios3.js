//Problema 1

let arreglo=[2,32,43,[4],[3]]

function  sortIt(arreglo){
    arreglo.sort( function (a, b) { return a - b})
    return arreglo
}
sortIt(arreglo)
console.log(arreglo)

//Problema 2

let arre=[2,37,3,1,6]

function sieteCrazy(arreglo){
    arreglo=arreglo.toString()
    let pos=arreglo.indexOf("7")
    if(pos>=0)-
        console.log("Crazy");
    else   
        console.log("No hay ningun 7 en el arreglo");

}
sieteCrazy(arre)

//Problema 3
var arr = [2,3,20,15,8,3];

function leader(arreglo){
    let n
    let lead=[]
    let le=arreglo[arreglo.length-1]
    lead.push(le)
    for(let i = arreglo.length-2 ;i >=0;i--)
    {
        if(arreglo[i] > le)
        {
            n=arreglo[i]
            lead.push(n)
        }
    }
           
    return lead
}

console.log(leader(arr));

//Problema 4

function hallaAsesino(cadena){
    let palabra="asesINo"
    let pos=cadena.toLowerCase().indexOf(palabra.toLowerCase())
    if(pos !== -1)
        console.log("Hallé al asesino en la posicion "+pos);
    else
        console.log("No encontré al asesino");
}
hallaAsesino("soy un AseSino")

//Problema 5

a=[[1, 2],[3, 4]]
function flatten(arreglo){
    let pila = [...arreglo]
    let resu=[]
    while(pila.length){
        let elemento = pila.pop()
        if(Array.isArray(elemento))
            pila.push(...elemento)
        else    
            resu.push(elemento)
    }
    return resu.reverse()
}

console.log(flatten(a));