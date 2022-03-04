const ip = "10.0.0.0"               //Variable que alamcena la ip que ingresa usuario
let octects = ip.split('.')         //Hacemos los octetos de la ip separando la ip por el punto
let defaultMask                     //Variable para la mascara por defecto      
let netClass                        //Variable apra la clase por defecto 
let expo                            //Variable que guardara el exponente al que sera elevado el 2 para obtener subredes y hosts
let subnetBits                      //Variable que almacena los bits de subnet
let hostBits                        //Variable que almacena el número de bits para host
let maskBits                        //Variable que almacena la cadena de bits de la mascara
let res = 0                         //Variable que almacena res; variable constante para calculos
let firstSubNet = []                //Arreglo que contendra la primera subred
let octectToModify = 3              //Variable para saber el octeto de la ip a modificar, por defecto se modifica el 3


//Rrecorremos cada octeto y lo ocnvertimos en un número entero
octects = octects.map(octect => Number.parseInt(octect,10))


/** 
 *  Función utilizada para validar una dirección IP ingresada por el uusario
 *  Hacemos uso de una expresión regular que indica si una IP es válida o no
 *  @param ip La ip escrita por el usario
 *  @returns true si es ip valida o false en caso de no ser una ip valida
*/
const validateIP = (ip) => {
    //  Testeamos la ip del usuairo con la expresion regular
    if(/^(22[0-3]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/.test(ip))
        return true     //  True si es valida
    else return false   //  False si no es valida
}

/**
 *  Función que arroja un mensaje si la ip no es valida
 *  @param * No recibe parametros
 *  @returns Mensaje indicando que no es una ip válida 
*/
const isIpValid = () =>{
    //Si la ip no es válida arrojamos mensaje indicando que ingrese otra IP
    if(!validateIP(ip)) 
        console.log("Inserte una IP válida o que pertenezca a clase A, B o C");
} 

//Llamada a la funciónq queverifica la ip
isIpValid()


if(octects[0] >= 0 && octects[0]<= 127){
    netClass = "Clase A"
    defaultMask = "255.0.0.0"
    maskBits = "11111111000000000000000000000000"
    hostBits = 24
    netBits = 8
    firstSubNet = [octects[0], 0, 0, 0]
}
if(octects[0] >= 128 && octects[0]<= 191){
    netClass = "Clase B"
    defaultMask = "255.255.0.0"
    maskBits = "11111111111111110000000000000000" 
    hostBits = 16
    netBits = 16
    firstSubNet = [octects[0], octects[1], 0, 0]

}
if(octects[0] >= 192 && octects[0]<= 223){
    netClass = "Clase C"
    defaultMask = "255.255.255.0"
    maskBits = "11111111111111111111111100000000"  
    hostBits = 8
    netBits = 24
    firstSubNet = [octects[0], octects[1], octects[2], 0]

}

/*
    Lo siguiente servirà para calcular la nueva submascara, sumamos la cantidad total de los 4 bytes de la red
    para despues hacer corrimeinto de bits obteniendo la nueva submascara
*/
for(i=0;i<32;i++){
    res = res + Math.pow(2,i)
}

res

//Función que calcula el prefijo de la nueva submascara. sumamos los bits destinados para red dependiendo la clase y la potencia necesaria para las subredes
const prefixFunc = powSubnet => netBits + powSubnet
//Función que calcula nueva mascara
const getNewMask = (expo) => {
    return ( ( ( res << expo ) >>> 0).toString(2)).match(/.{1,8}/g).map(byte => parseInt(byte, 2)) 
}

//Función para calcular el salto
const hopFunc = (prefix, newMask) => {
    let hop 
    if(netClass == "Clase A")
    if (prefix >= 8 && prefix <= 16){
        hop = 256 - newMask[1]
        octectToModify = 1
    } else if(prefix >= 17 && prefix <=24){
        hop = 256 - newMask[2]
        octectToModify = 2
    } else hop = 256 - newMask[3]

    if(netClass == "Clase B")
        if (prefix >= 16 && prefix <= 24){
            hop = 256 - newMask[2]
            octectToModify = 2
        } else hop = 256 - newMask[3]

    if(netClass == "Clase C")
        hop = 256 - newMask[3]

    return hop
}

//Función que calcula la lista de subredes de la red
const subnetsCalc = (hop, totalSubnetworks) => {
    const temporalNet = new Array(totalSubnetworks).fill(firstSubNet)
    let acc = 0
    let acc2 = 0
    let acc3 = 0
    let subnets = []
    subnets = temporalNet.map( (subnet, index) =>{

        if(index == 0)
            return subnet
        const copy = octects.slice(0)
    
        subnet = copy
        acc += hop
        subnet[octectToModify] = acc
        
        if(subnet[octectToModify] >= 256){
            acc = 0
            acc2 += 1
            subnet[octectToModify] = 0
            subnet[octectToModify-1] = acc2
        }
        if(subnet[octectToModify-1] >= 256){
            acc = 0
            acc2 = 0
            acc3 += 1
            subnet[octectToModify-1] = 0
            subnet[octectToModify-2] = acc3
        } 
        subnet[octectToModify] = acc
        subnet[octectToModify-1] = acc2
        subnet[octectToModify-2] = acc3
        
        if(netClass == "Clase A"){
            subnet = subnet.splice(0)
            subnet[0] = octects[0]
        }
        if(netClass == "Clase B"){
            subnet[0] = octects[0]
            subnet[1] = octects[1]
        }
        if(netClass == "Clase C"){
            subnet[0] = octects[0]
            subnet[1] = octects[1]
            subnet[2] = octects[2]
        }
    
        return subnet
    })

    return subnets
}

//Calculando las direcciones de host para una subred dada
const hostCalc = (sub, gotHosts) => {
    let acc = 0
    let acc2 = 0
    let acc3 = 0
    let temp = new Array(gotHosts).fill(sub)
    let hostXsubnet = []
    acc = sub[3]
    acc2 = sub[2]
    acc3 = sub[1]

    hostXsubnet = temp.map((s,index) => {

        const copy = sub.slice(0)
        s = copy

        acc += 1
        s[3] = acc
    
        if(s[3] >= 256){
            acc = 0
            acc2 += 1
            s[3] = 0
            s[2] = acc2
        }
        if( s[2] >= 256){
            acc = 0
            acc2 = 0
            acc3
            acc3 += 1
            s[2] = 0
            s[1] = acc3
            
        } 
        s[3] = acc
        s[2] = acc2
        s[1] = acc3

        if(netClass == "Clase A"){
            s = s.splice(0)
            s[0] = sub[0]
        }
        if(netClass == "Clase B"){
            s[0] = sub[0]
            s[1] = sub[1]
        }
        if(netClass == "Clase C"){
            s[0] = sub[0]
            s[1] = sub[1]
            s[2] = sub[2]
         }

        return s

    })
    return hostXsubnet
}
//Usando subredes
const requireSubnets = 4194304

//Restricciones
if(netClass == "Clase A" && requireSubnets > 4194304)
    console.log("Inserte un número valido de subredes, inserte un valor de 1 a 4194304");
if(netClass == "Clase B" && requireSubnets > 16384)
    console.log("Inserte un número valido de subredes, inserte un valor de 1 a 16384");
if(netClass == "Clase C" && requireSubnets > 64)
    console.log("Inserte un número valido de subredes, inserte un valor de 1 a 64");
const expoSubnets = Math.ceil(Math.log2(requireSubnets))
expoSubnets //modificar en mascara
const gotSubnets = Math.pow(2,expoSubnets)
gotSubnets
const hostPow = hostBits - expoSubnets
hostPow //para calcular total hosts
const totalHostSubnet =  Math.pow(2,hostPow)-2
totalHostSubnet
    //obteniendo nueva mascara
const newMaskSubnet = getNewMask(hostPow)
newMaskSubnet



const prefixSubnet = prefixFunc(expoSubnets)
prefixSubnet

const hopSubnet = hopFunc(prefixSubnet, newMaskSubnet)
hopSubnet

const subnetListSubnet = subnetsCalc(hopSubnet, gotSubnets)

subnetHost = subnetListSubnet[0]
subnetHost

console.log(subnetListSubnet);
console.log(subnetListSubnet[subnetListSubnet.length-1]);

const hostsList = hostCalc(subnetHost, totalHostSubnet)

console.log(hostsList[hostsList.length-1]);
console.log(hostsList);
const broadcastAdrrSubnet = hostsList[hostsList.length-1]
broadcastAdrrSubnet[3] = broadcastAdrrSubnet[3]+1
broadcastAdrrSubnet

//Usando Hosts
let requireHosts = 1

//Restricciones
if( netClass == "Clase A" && requireHosts > 16777214 )
    console.log("Inserte una cantidad de Hosts válida, inserte un valor de 1 a 16777214");
if( netClass == "Clase B" && requireHosts > 65534 )
    console.log("Inserte una cantidad de Hosts válida, inserte un valor de 1 a 65534");
if( netClass == "Clase C" && requireHosts > 254 )
    console.log("Inserte una cantidad de Hosts válida, inserte un valor de 1 a 254");
    
let gotHosts
expoHost = Math.ceil(Math.log2(requireHosts+2))
expoHost
gotHosts = Math.pow(2,expoHost)-2
gotHosts
let subnetPow = hostBits - expoHost
hostBits
subnetPow
const totalSubnetworksHost = Math.pow(2,subnetPow)
totalSubnetworksHost
const newMaskHost = getNewMask(expoHost)
newMaskHost
const prefixHost = prefixFunc(subnetPow)
prefixHost

const hopHost = hopFunc(prefixHost, newMaskHost)        
hopHost
octects

const subnetList = subnetsCalc(hopHost, totalSubnetworksHost)
subnetHost = subnetList[0]
subnetHost
gotHosts
console.log(subnetList);
console.log(subnetList[subnetList.length-1]);

const totalHost = hostCalc(subnetHost, gotHosts)

console.log(totalHost[totalHost.length-1]);
console.log(totalHost);
const broadcastAdrr = totalHost[totalHost.length-1]
broadcastAdrr[3] = broadcastAdrr[3]+1
broadcastAdrr

//Usando el prefijo

const requirePrefix = 24
//Restricciones
if( requirePrefix < 8 || requirePrefix > 30 ){
    console.log("Prefijo no valido, prueba con un valor de 8 a 30");
}
if( netClass == "Clase B" && requirePrefix < 16 )
    console.log("Prefijo no válido para clase B, inserte un valor de 16 a 30");

if( netClass == "Clase C" && requirePrefix < 24 )
    console.log("Prefijo no válido para clase C, inserte un valor de 24 a 30");

const subnetPowPrefix = requirePrefix - netBits
subnetPowPrefix
const hostPowPrefix = hostBits - subnetPowPrefix
hostPowPrefix

const newMaskPrefix = getNewMask(hostPowPrefix)
newMaskPrefix

const totalHostPrefix = Math.pow(2,hostPowPrefix)-2
totalHostPrefix

const totalSubnetsPrefix = Math.pow(2,subnetPowPrefix)
totalSubnetsPrefix

const hopPrefix = hopFunc(requirePrefix, newMaskPrefix)
hopPrefix

const subnetsListPrefix = subnetsCalc(hopPrefix, totalSubnetsPrefix)
console.log(subnetsListPrefix);
console.log(subnetsListPrefix[subnetsListPrefix.length-1]);

const hostPrefix = subnetsListPrefix[0]
hostPrefix
const hostListPrefix = hostCalc(hostPrefix, totalHostPrefix)
console.log(hostListPrefix);
console.log(hostListPrefix[hostListPrefix.length-1]);
const broadcastAdrrPrefix = hostListPrefix[hostListPrefix.length-1]
broadcastAdrrPrefix[3] = broadcastAdrrPrefix[3]+1
broadcastAdrrPrefix