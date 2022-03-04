export default{
    methods: {
        /**
         * Función que calcula las direcciones de hosts para una subred especifica
         * @param netClass La clase de la dirección de la IP
         * @param sub La subred elegida
         * @param gotHosts El número de hosts total
         * @returns Retorna las di|ecciones de host para la subred especifica
        */
         hostCalc (sub){
            let acc = 0                         //  Variable auxiliar de acumulador
            let acc2 = 0                        //  Variable auxiliar de acumulador
            let acc3 = 0                        //  Variable auxiliar de acumulador

            //  Variable temporal que guardara las direcciones de host sin calcular
            let temp = new Array(this.totalHostSubnet).fill(sub)
            
            acc = sub[3]                        //  Inicializamos el ultimo octeto
            acc2 = sub[2]                       //  Inicializamos el tercer octeto
            acc3 = sub[1]                       //  Inicializamos el segundo octeto

            //  Recorremos cada red del arreglo temporal para ahora si calcular las redes de host
            this.hostsList = temp.map((s) => {

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
                if(this.completeIP.netClass == "Clase A"){
                    s = s.splice(0)
                    s[0] = sub[0]
                }
                //  Si la clase es tipo B no se cambian los primeros dos octetos
                if(this.completeIP.netClass == "Clase B"){
                    s[0] = sub[0]
                    s[1] = sub[1]
                }
                //  Si la clase es tipo C no se cambian los primeros tres octetos
                if(this.completeIP.netClass == "Clase C"){
                    s[0] = sub[0]
                    s[1] = sub[1]
                    s[2] = sub[2]
                }

                return s                            //  Retornamo cada red de host

            })
            const broad = this.hostsList[this.hostsList.length-1]
            broad[3] = broad[3]+1
            this.broadcastAdrrSubnet = broad.join('.')
            broad[3] = broad[3]-1
        }
    },
}