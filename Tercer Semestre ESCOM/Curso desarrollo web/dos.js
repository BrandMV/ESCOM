let arre=[2,37,3,1,6]

function sieteCrazy(arreglo){
    arreglo=arreglo.toString()
    let pos=arreglo.indexOf("7")
    if(pos>=0)
        console.log("Crazy");
    else   
        console.log("No hay ningun 7 en el arreglo");

}
sieteCrazy(arre)