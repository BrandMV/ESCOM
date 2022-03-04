


const ip = "192.0.0.0"               //Variable que alamcena la ip que ingresa usuario

let expo                            //Variable que guardara el exponente al que sera elevado el 2 para obtener subredes y hosts

let octectToModify = 3              //Variable para saber el octeto de la ip a modificar, por defecto se modifica el último

/**
 * Función que obtiene los octetos de la ip ingresada
 * @param ip La ip escrita por el usuario 
 * @returns Los octetos de la dirección ip ingresada
*/
const getOctects = (ip) => ip.split('.').map(octect => Number.parseInt(octect,10))

const ipOctects = getOctects(ip)    //  Mandamos a llamar a la función que calcula los octetos

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

isIpValid()         //  Llamada a la función que valida la IP

/**
 * Función que inicializa la ip ingresada por el usuario con su clase, mascara, bits para host, la primera subnet, etc.
 * @param ipOctects Los octetos de la ip ingresada por el usuario
 * @returns La ip con su información por defecto
*/
const getIpObject = (ipOctects) => {
    let ObjectIp = new Object()                                 //  Nuevo objeto para la IP

    if(ipOctects[0] >= 0 && ipOctects[0]<= 127){                //  Si la ip es clase A se inicializan los valores
         ObjectIp = {                                           
            netClass    : "Clase A",                            //  Asignamos la clase
            defaultMask : "255.0.0.0",                          //  Asignamos la mascara por defecto
            maskBits    : "11111111000000000000000000000000",   //  Asiganamos los bits de la mascara
            hostBits    : 24,                                   //  Los bits para host
            netBits     : 8,                                    //  Los bits para subredes
            firstSubNet : [ipOctects[0], 0, 0, 0]               //  La primera subred de la direccion
        }
    }
    if(ipOctects[0] >= 128 && ipOctects[0]<= 191){              //  Si la ip es clase B se inicializan los valores
         ObjectIp = {
            netClass    : "Clase B",                            //  Asignamos la clase
            defaultMask : "255.255.0.0",                        //  Asignamos la mascara por defecto
            maskBits    : "11111111111111110000000000000000",   //  Asiganamos los bits de la mascara
            hostBits    : 16,                                   //  Los bits para host
            netBits     : 16,                                   //  Los bits para subredes
            firstSubNet : [ipOctects[0], ipOctects[1], 0, 0]    //  La primera subred de la direccion
        }
    }
    if(ipOctects[0] >= 192 && ipOctects[0]<= 223){       //  Si la ip es clase C se inicializan los valores
         ObjectIp = {
            netClass    : "Clase C",                            //  Asignamos la clase
            defaultMask : "255.255.255.0",                      //  Asignamos la mascara por defecto
            maskBits    : "11111111111111111111111100000000",   //  Asiganamos los bits de la mascara
            hostBits    : 8,                                    //  Los bits para host
            netBits     : 24,                                   //  Los bits para subredes
            firstSubNet : [ipOctects[0], ipOctects[1], ipOctects[2], 0] //  La primera subred de la direccion
        }
    }

    return ObjectIp                         //  Retornamos la ip con sus atributos
}


const completeIP = getIpObject(ipOctects)   //  Mandamos a llamar la función que obtiene los detalles de la IP

/**
 * Función que calcula una constante que nos servirá para el calculo de las nuevas submascaras de las redes
 * @returns Retorna la cantidad total de los 4 bytes que tiene la red
*/
const auxSubmaskCalc = () =>{
    let res = 0;                    //  Inicializamos en 0
    for(i=0;i<32;i++)               //  Ciclo hasta el número de bits de la red
        res = res + Math.pow(2,i)   //  Vamos sumando de acuerdo a la potencia de i
    
    return res                      //  Retornamos el resultado
}

const res = auxSubmaskCalc()        //Mandamos a llamar la función que nos retorna la constante auxiliar para calculo de submascaras nuevas


/**
 * Función que calcula el prefijo de la nueva submascara
 * @param powSubnet Es la potencia a la que esta elevada la subred
 * @param netBits   Los bits de red de la dirección
 * @returns El prefijo de la nueva submascara de la red
 */
const prefixFunc = ({ netBits }, powSubnet) => netBits + powSubnet     //Se suman los bits de red con la potencia de la subred

/**
 * Función que calcula la nueva mascara 
 * @param expo El exponente al que esta elevado 
 * @param res  Resultado obtenido de la función auxSubmaskCalc
 * @returns la nueva mascara de la red
*/
const getNewMask = (expo,res) => {
    /*
        La nueva mascara esta obtenida en una sola línea, se desglozará para mejor entendimiento
            (res << expo) >>> 0 Primero se realiza un corrimiento de bits a la izquierda de acuerdo al exponente
                              Posteriormente un ocrrimiento sin signo a la derecha para obtener la cadena de bits completa
                              de la mascara
            .toString(2) Pasamos a binario la cantidad obtenida con las operaciones anteriores
            .match()    Tomamos 8 bits de la cadena de 32 bits
            .map()      Recorremos de 8 en 8 los bits de la mascara para convertirlos en un entero decimal
    */
    return ( ( ( res << expo ) >>> 0).toString(2)).match(/.{1,8}/g).map(byte => parseInt(byte, 2)) 
}

/**
 * Función que calcula el salto para ir calculando las subredes de la dirección requerido de acuerdo a los hosts, subredes o prefijo
 * @param {*} prefix El prefijo de la red
 * @param {*} newMask La nueva mascara calculada anteriormente
 * @param {*} netClass La clase de la dirección Ip
 * @returns Retorna el salto para cada subred
*/
const hopFunc = ({ netClass } , prefix, newMask) => {
    let hop                                 
    if(netClass == "Clase A")                       //  Si la clase es A:
        if (prefix >= 8 && prefix <= 16){           
            hop = 256 - newMask[1]                      //  Si el prefijo esta entre 8 y 16 el salto será de 256 menos el segundo octeto     
            octectToModify = 1                               //  El octeto a modificar sera el segundo
        } else if(prefix >= 17 && prefix <=24){         //  Si el prefijo esta entre 17 y 24:
            hop = 256 - newMask[2]                          //  El salto sera 256 - el octeto 3 de la red
            octectToModify = 2                              //  El octeto a modificar sera el 3
        } else hop = 256 - newMask[3]                   //  En otro caso el salto sera 256 menos el valor del ultimo octeto

    if(netClass == "Clase B")                       //  Si la clase es B:
        if (prefix >= 16 && prefix <= 24){              //Si el octeto esta entre 16 y 24
            hop = 256 - newMask[2]                          //  El salto sera 256 - el octeto 3 de la red
            octectToModify = 2                              //  El octeto a modificar sera el 3
        } else hop = 256 - newMask[3]               //  En otro caso el salto sera 256 menos el valor del ultimo octeto

    if(netClass == "Clase C")                       //  Si la clase es C:
        hop = 256 - newMask[3]                          //  En otro caso el salto sera 256 menos el valor del ultimo octeto       

    return hop                                      //Retornamos el salto resultante
}

//Función que calcula la lista de subredes de la red

/**
 * Función que calcula las subredes de la red
 * @param hop El salto de la red
 * @param totalSubnetworks La cantidad total de subredes que tiene la red
 * @param firstSubnet La primera subnet de la red
 * @param netClass La clase de la red
 * @returns La cantidad total de subredes que tiene la red expresada con sus octetos
 */
const subnetsCalc = ( { firstSubNet, netClass } ,hop, totalSubnetworks) => {
    //En un arreglo temporal vamos a guardar arreglos de subredes que serán modificadas despues
    const temporalNet = new Array(totalSubnetworks).fill(firstSubNet)
    let acc = 0         //  Variable auxiliar de acumulador
    let acc2 = 0        //  Variable auxiliar de acumulador
    let acc3 = 0        //  Variable auxiliar de acumulador
    let subnets = []    //  Arreglo que guardará las subredes

    //  Por cada subred temporal se calculara la subred real
    subnets = temporalNet.map( (subnet, index) =>{

        if(index == 0)                      //  Si pasamos por la primera subred la guardamos en el arreglo
            return subnet                   //  Retornamos la primera subred

        const copy = ipOctects.slice(0)     //  Realizamos una copia de los octetos de la red
    
        subnet = copy                       //  Se copian los octetos en cada subred
        acc += hop                          //  Se va acumulando el salto en el primer acumulador
        subnet[octectToModify] = acc        //  De acuerdo al octetoa  modificar
        
        if(subnet[octectToModify] >= 256){  //  Si el octeto a modificar sobrepasa los 255 se procede a modificar el anterior
            acc = 0                         //  Empezamos el acumular en 0 de nuevo
            acc2 += 1                       //  Para calcular las subredes vamos sumando uno al acumulador dos
            subnet[octectToModify] = 0      //  El octeto a modificar se pondrá en 0
            subnet[octectToModify-1] = acc2 //  Ahora si comenzamos con el octeto a anterior a modificarlo
        }
        if(subnet[octectToModify-1] >= 256){//  Si el octeto a modificar-1 sobrepasa los 255 se procede a modificar el octeto-2
            acc = 0                         //  Reiniciamos el primer acumulador
            acc2 = 0                        //  Reiniciamos el segundo acumulador   
            acc3 += 1                       //  Procedemos a aumentar el acumulador 3
            subnet[octectToModify-1] = 0    //  Reiniciamos el octetoa modificar-1
            subnet[octectToModify-2] = acc3 //  Comenzamos a modificar el octeto a modificar - 2
        } 
        subnet[octectToModify] = acc        //  Finalmente el octeto a modificar será el acumulador
        subnet[octectToModify-1] = acc2     //  El octeto-1 será el acumulador 2
        subnet[octectToModify-2] = acc3     //  El octeto-2 sera el acumulador 3
        
        if(netClass == "Clase A"){          //  Si la clase es tipo A
            subnet = subnet.splice(0)           //  Copiamos la subnet
            subnet[0] = ipOctects[0]            //  El primero octeto de la red será el primer octeto de la red ingresada
        }
        if(netClass == "Clase B"){          //  Si la clase es tipo B
            subnet[0] = ipOctects[0]            //  El primer octeto de cada subred sera el primero de la red ingresada   
            subnet[1] = ipOctects[1]            //  El segundo octeto de cada subred sera el segundo de la red ingresada
        }
        if(netClass == "Clase C"){          //  Si la clase es tipo C
            subnet[0] = ipOctects[0]            //  El primer octeto de cada subred sera el primero de la red ingresada    
            subnet[1] = ipOctects[1]            //  El segundo octeto de cada subred sera el segundo de la red ingresada
            subnet[2] = ipOctects[2]            //  El tercer octeto de cada subred sera el tercer de la red ingresada
        }
    
        return subnet                       //  Retornamos cada subred
    })      

    return subnets                          //  Retornamos todas las subredes
}

//Calculando las direcciones de host para una subred dada

/**
 * Función que calcula las direcciones de hosts para una subred especifica
 * @param netClass La clase de la dirección de la IP
 * @param sub La subred elegida
 * @param gotHosts El número de hosts total
 * @returns Retorna las direcciones de host para la subred especifica
*/
const hostCalc = ( { netClass } ,sub, gotHosts) => {
    let acc = 0                         //  Variable auxiliar de acumulador
    let acc2 = 0                        //  Variable auxiliar de acumulador
    let acc3 = 0                        //  Variable auxiliar de acumulador

    //  Variable temporal que guardara las direcciones de host sin calcular
    let temp = new Array(gotHosts).fill(sub)
    
    let hostXsubnet = []                //  Arreglo que almacena las redes de host      
    acc = sub[3]                        //  Inicializamos el ultimo octeto
    acc2 = sub[2]                       //  Inicializamos el tercer octeto
    acc3 = sub[1]                       //  Inicializamos el segundo octeto

    //  Recorremos cada red del arreglo temporal para ahora si calcular las redes de host
    hostXsubnet = temp.map((s) => {

        const copy = sub.slice(0)       //  Copiamos la subred
        s = copy                        //  Se almacena la copioa en cada subred

        acc += 1                        //  Vamos incrementando en uno el primer acumulador
        s[3] = acc                      //  El ultimo octeto sera igual al primer acumulador
        
        /*
            Si el ultimo octeto rebasa los 255 se comienza  a incrementar el acumulador 2 el cual sera
            lo que incremente el tercer octeto de la red de host. Este acumulador crecerá de uno en uno
        */
        if(s[3] >= 256){
            acc = 0
            acc2 += 1
            s[3] = 0
            s[2] = acc2
        }
        /*
            Si el tercer octeto rebasa los 255 se comienza  a incrementar el acumulador 3 el cual sera
            lo que incremente el segundo octeto de la red de host. Este acumulador crecerá de uno en uno
        */
        if( s[2] >= 256){
            acc = 0
            acc2 = 0
            acc3
            acc3 += 1
            s[2] = 0
            s[1] = acc3
            
        } 
        s[3] = acc                      //  El acumulador 1 será el ultimo octeto
        s[2] = acc2                     //  El acumulador 2 será el tercer octeto
        s[1] = acc3                     //  El acumulador 3 sera el segundo octeto

        //  Si la clase es tipo A no se cambia el primer octeto
        if(netClass == "Clase A"){
            s = s.splice(0)
            s[0] = sub[0]
        }
        //  Si la clase es tipo B no se cambian los primeros dos octetos
        if(netClass == "Clase B"){
            s[0] = sub[0]
            s[1] = sub[1]
        }
        //  Si la clase es tipo C no se cambian los primeros tres octetos
        if(netClass == "Clase C"){
            s[0] = sub[0]
            s[1] = sub[1]
            s[2] = sub[2]
         }

        return s                            //  Retornamo cada red de host

    })
    return hostXsubnet                      //  Retornamos todas las redes de host
}
//Usando subredes

//Restricciones

/**
 * Función que verifica que las sub redes requeridas por el usuario sean acordes al tipo de clase de la red
 * @param netClass La clase de la ip ingresada 
 * @param requireSubnets El numero de subredes requeridas por el usuario
*/
const subnetsRestric = ( { netClass }, requireSubnets ) => {
    //  Si es clase A y se requieren mas subredes de las que se pueden crear manda error
    if(netClass == "Clase A" && requireSubnets > 4194304)
        console.log("Inserte un número valido de subredes, inserte un valor de 1 a 4194304");
    
    //  Si es clase B y se requieren mas subredes de las que se pueden crear manda error
    if(netClass == "Clase B" && requireSubnets > 16384)
        console.log("Inserte un número valido de subredes, inserte un valor de 1 a 16384");

    //  Si es clase C y se requieren mas subredes de las que se pueden crear manda error
    if(netClass == "Clase C" && requireSubnets > 64)
        console.log("Inserte un número valido de subredes, inserte un valor de 1 a 64");
}

//  Cantidad de subredes requeridas
const requireSubnets = 2 

//  Mandamos a llamar a la función de las restricciones
subnetsRestric(completeIP, requireSubnets)


const expoSubnets = Math.ceil(Math.log2(requireSubnets))        //  Calculamos el exponente de la subred
const gotSubnets = Math.pow(2,expoSubnets)                      //  Calculamos la cantidad de subredes totales
const hostPow = completeIP.hostBits - expoSubnets               //  Calculamos la potencia necesaria para calcular los hosts                  
const totalHostSubnet =  Math.pow(2,hostPow)-2                  //  Calculammos el numero total de hosts que tendra cada subred
    //obteniendo nueva mascara
const newMaskSubnet = getNewMask(hostPow, res)                   //  Mandamos a llamar a la funcion que calcula nueva mascara

const prefixSubnet = prefixFunc(completeIP ,expoSubnets)                // Calculamos el prefijo

const hopSubnet = hopFunc(completeIP ,prefixSubnet, newMaskSubnet)      //  Calculamos el salto de cada subred
//  Terminan calculos necesarios

const subnetListSubnet = subnetsCalc(completeIP ,hopSubnet, gotSubnets) //  Calculamos la lista de sub redes

subnetHost = subnetListSubnet[0]

console.log(subnetListSubnet);
console.log(subnetListSubnet[subnetListSubnet.length-1]);

const hostsList = hostCalc(completeIP ,subnetHost, totalHostSubnet)     //  Calculamos la lista de hosts para una subred dada

console.log(hostsList[hostsList.length-1]);
console.log(hostsList);

/**
 * Función que calcula la dirección de broadcast
 * @param hosts Lista que contiene las direcciones de host 
 * @returns Retorna la direccion de broadcast para la subred
*/
const broadcastCalc = (hosts) =>{
    const broad = hosts[hosts.length-1] //  Almacenamos la última dirección de host
    broad[3] = broad[3]+1               //  Sumamos 1 al ultiumo octeto de la red, esta sera la dir. broadcast
    return broad                        //  Retornamos la dirección broadcast
} 
    
const broadcastAdrrSubnet = broadcastCalc(hostsList)    //  LLamamos a la función que calcula la broadcast

//Usando Hosts

let requireHosts = 1

//Restricciones
const hostRestric = ({ netClass }, requireHosts) => {

    //  Si la clase es A y la cantidad de hosts es mayor a la posible regresamos error
    if( netClass == "Clase A" && requireHosts > 16777214 )
        console.log("Inserte una cantidad de Hosts válida, inserte un valor de 1 a 16777214");
    
    //  Si la clase es B y la cantidad de hosts es mayor a la posible regresamos error
    if( netClass == "Clase B" && requireHosts > 65534 )
        console.log("Inserte una cantidad de Hosts válida, inserte un valor de 1 a 65534");

    //  Si la clase es C y la cantidad de hosts es mayor a la posible regresamos error
    if( netClass == "Clase C" && requireHosts > 254 )
        console.log("Inserte una cantidad de Hosts válida, inserte un valor de 1 a 254");
}

hostRestric(completeIP, requireHosts)                   //  Llamamos a la función que verifica los hosts

const expoHost = Math.ceil(Math.log2(requireHosts+2))   //  Calculamos el exponente necesario para obtener los hosts

const gotHosts = Math.pow(2,expoHost)-2                 //  Calculamos la cantidad de hosts

let subnetPow = completeIP.hostBits - expoHost          //  Calculamos la potencia de la subred

const totalSubnetworksHost = Math.pow(2,subnetPow)      //  Calculamos el total se subredes

const newMaskHost = getNewMask(expoHost, res)           //  Calculamos la nueva mascara
const prefixHost = prefixFunc(completeIP, subnetPow)    //  Calculammos el prefijo                

const hopHost = hopFunc(completeIP, prefixHost, newMaskHost)        

const subnetList = subnetsCalc(completeIP, hopHost, totalSubnetworksHost)   //  Calculamos la lista de subredes
subnetHost = subnetList[0]

console.log(subnetList);
console.log(subnetList[subnetList.length-1]);

const totalHost = hostCalc(completeIP, subnetHost, gotHosts)    //  Calculamos los hosts de una subred dada       

console.log(totalHost[totalHost.length-1]);
console.log(totalHost);

const broadcastAddr = broadcastCalc(totalHost)                  //  Calculamos la red de broadcast

//Usando el prefijo

const requirePrefix = 24     // Prefijo requerido
//Restricciones

/**
 * Función que indica las restricciones para el prefijo ingresado por el usuario
 * @param netClass La clase de la red
 * @param requirePrefix El prefijo deseado por el usuario
*/
const prefixRestric = ({ netClass }, requirePrefix) => {
    //  Si el prefijo no es valido se produce un mensaje de error
    if( requirePrefix < 8 || requirePrefix > 30 )
        console.log("Prefijo no valido, prueba con un valor de 8 a 30");
    
    //  Si el prefijo no es valido para la clase B se produce un mensaje de error
    if( netClass == "Clase B" && requirePrefix < 16 )
        console.log("Prefijo no válido para clase B, inserte un valor de 16 a 30");
    
    //  Si el prefijo no es valido para la clase C se produce un mensaje de error
    if( netClass == "Clase C" && requirePrefix < 24 )
        console.log("Prefijo no válido para clase C, inserte un valor de 24 a 30");
}

prefixRestric(completeIP, requirePrefix)        //  Llamamos a la funcion paara verificar el prefijo


const subnetPowPrefix = requirePrefix - completeIP.netBits                          //  Calculamos la potencia para subredes
const hostPowPrefix = completeIP.hostBits - subnetPowPrefix                         //  Calculamos la potencia para hosts

const newMaskPrefix = getNewMask(hostPowPrefix, res)                                //  Calculamos la nueva mascara

const totalHostPrefix = Math.pow(2,hostPowPrefix)-2                                 //  Calculamos el total de host 

const totalSubnetsPrefix = Math.pow(2,subnetPowPrefix)                              //  Total de subredes

const hopPrefix = hopFunc(completeIP, requirePrefix, newMaskPrefix)                 //  Calculamos el salto

const subnetsListPrefix = subnetsCalc(completeIP, hopPrefix, totalSubnetsPrefix)    //  Calculamos las direcciones de subredes
console.log(subnetsListPrefix);
console.log(subnetsListPrefix[subnetsListPrefix.length-1]);

const hostPrefix = subnetsListPrefix[0]
const hostListPrefix = hostCalc(completeIP, hostPrefix, totalHostPrefix)            //  Calculamos las direcciones de hosts de una subred
console.log(hostListPrefix);
console.log(hostListPrefix[hostListPrefix.length-1]);

const broadcastAdrrPrefix = broadcastCalc(hostListPrefix)                           //  Calculamos la direción de broadcast