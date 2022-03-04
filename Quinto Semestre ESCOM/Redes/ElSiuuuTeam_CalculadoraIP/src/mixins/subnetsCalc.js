export default{
    methods: {
          /**
         * Función que calcula las subredes de la red
         * @param hop El salto de la red
         * @param totalSubnetworks La cantidad total de subredes que tiene la red
         * @param firstSubnet La primera subnet de la red
         * @param netClass La clase de la red
         * @returns La cantidad total de subredes que tiene la red expresada con sus octetos
         */
           subnetsCalc(){
            // this.subnetListSubnet = []
            //En un arreglo temporal vamos a guardar arreglos de subredes que serán modificadas despues
            const temporalNet = new Array(this.gotSubnets).fill(this.completeIP.firstSubNet)
            let acc = 0         //  Variable auxiliar de acumulador
            let acc2 = 0        //  Variable auxiliar de acumulador
            let acc3 = 0        //  Variable auxiliar de acumulador
            this.hasSubnets = true
            //  Por cada subred temporal se calculara la subred real
            this.subnetListSubnet = temporalNet.map( (subnet, index) =>{

                if(index == 0)                      //  Si pasamos por la primera subred la guardamos en el arreglo
                    return subnet                   //  Retornamos la primera subred

                const copy = this.ipOctects.slice(0)     //  Realizamos una copia de los octetos de la red
            
                subnet = copy                       //  Se copian los octetos en cada subred
                acc += this.hopSubnet                          //  Se va acumulando el salto en el primer acumulador
                subnet[this.octectToModify] = acc        //  De acuerdo al octetoa  modificar
                
                if(subnet[this.octectToModify] >= 256){  //  Si el octeto a modificar sobrepasa los 255 se procede a modificar el anterior
                    acc = 0                         //  Empezamos el acumular en 0 de nuevo
                    acc2 += 1                       //  Para calcular las subredes vamos sumando uno al acumulador dos
                    subnet[this.octectToModify] = 0      //  El octeto a modificar se pondrá en 0
                    subnet[this.octectToModify-1] = acc2 //  Ahora si comenzamos con el octeto a anterior a modificarlo
                }
                if(subnet[this.octectToModify-1] >= 256){//  Si el octeto a modificar-1 sobrepasa los 255 se procede a modificar el octeto-2
                    acc = 0                         //  Reiniciamos el primer acumulador
                    acc2 = 0                        //  Reiniciamos el segundo acumulador   
                    acc3 += 1                       //  Procedemos a aumentar el acumulador 3
                    subnet[this.octectToModify-1] = 0    //  Reiniciamos el octetoa modificar-1
                    subnet[this.octectToModify-2] = acc3 //  Comenzamos a modificar el octeto a modificar - 2
                } 
                subnet[this.octectToModify] = acc        //  Finalmente el octeto a modificar será el acumulador
                subnet[this.octectToModify-1] = acc2     //  El octeto-1 será el acumulador 2
                subnet[this.octectToModify-2] = acc3     //  El octeto-2 sera el acumulador 3
                
                if(this.completeIP.netClass == "Clase A"){          //  Si la clase es tipo A
                    subnet = subnet.splice(0)           //  Copiamos la subnet
                    subnet[0] = this.ipOctects[0]            //  El primero octeto de la red será el primer octeto de la red ingresada
                }
                if(this.completeIP.netClass == "Clase B"){          //  Si la clase es tipo B
                    subnet[0] = this.ipOctects[0]            //  El primer octeto de cada subred sera el primero de la red ingresada   
                    subnet[1] = this.ipOctects[1]            //  El segundo octeto de cada subred sera el segundo de la red ingresada
                }
                if(this.completeIP.netClass == "Clase C"){          //  Si la clase es tipo C
                    subnet[0] = this.ipOctects[0]            //  El primer octeto de cada subred sera el primero de la red ingresada    
                    subnet[1] = this.ipOctects[1]            //  El segundo octeto de cada subred sera el segundo de la red ingresada
                    subnet[2] = this.ipOctects[2]            //  El tercer octeto de cada subred sera el tercer de la red ingresada
                }
            
                return subnet                       //  Retornamos cada subred
            })      
            // this.broadcastAdrrSubnet = broadcastCalc()
            this.$toast.info('Da clic en una dirección para saber sus direcciones de host',{
                duration: 5000
            })
        }
    },
}