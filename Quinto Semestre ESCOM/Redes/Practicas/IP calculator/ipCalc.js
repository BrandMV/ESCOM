const ip = "10.0.0.0"
//Validación de IP
let octects = ip.split('.')
let defaultMask 
let netClass
let expo
let subnetBits
let hostBits
let maskBits
let res = 0
let firstSubNet = []
let octectToModify = 3

octects = octects.map(octect => Number.parseInt(octect,10))


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
        }else if(subnet[octectToModify-1] >= 256){
            acc = 0
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
const requireSubnets = 7
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

//Función que calcula el prefijo de la nueva submascara. sumamos los bits destinados para red dependiendo la clase y la potencia necesaria para las subredes
const prefixFunc = powSubnet => netBits + powSubnet

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
let requireHosts = 254
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

const requirePrefix = 25
//Restricciones
if( requirePrefix < 8 || requirePrefix > 30 ){
    console.log("Prefijo no valido, prueba con un valor de 8 a 30");
}


