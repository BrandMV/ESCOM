export default{
    methods: {
         /** 
         *  Función utilizada para validar una dirección IP ingresada por el uusario
         *  Hacemos uso de una expresión regular que indica si una IP es válida o no
         *  @returns true si es ip valida o false en caso de no ser una ip valida
        */
          validateIP(){
            //  Testeamos la ip del usuairo con la expresion regular
            if(/^(22[0-3]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/.test(this.ip))
                return true     //  True si es valida
            else return false   //  False si no es valida
        },
        /**
         *  Función que arroja un mensaje si la ip no es valida
         *  @returns Mensaje indicando que no es una ip válida 
        */
        isIpValid(){
            // Si la ip no es válida arrojamos mensaje indicando que ingrese otra IP
            if(!this.validateIP()){
                alert("Inserte una IP válida o que pertenezca a clase A, B o C")
                this.cards.splice(0)
            } 
            else{
           
                this.getOctects()           //  Obtenemos octetos de IP
                this.getIpObject()          //  Obtenemos la IP con sus datos
                this.auxSubmaskCalc()       //  Calculamos variable para ayudarnos a calculos
                this.cards[0] = {
                    icon:"fas fa-project-diagram", 
                    title: "clase de red", 
                    value: this.completeIP.netClass 
                }
                this.cards[1] =  {
                    icon:"fas fa-mask", 
                    title: "máscara de red", 
                    value: this.completeIP.defaultMask
                }
            }
        },
        /**
         * Función para obtener los octetos de la IP
         * @returns Los octetos de la dirección ip ingresada
        */
        getOctects(){ 
            this.ipOctects = []
            this.ip.split('.').map(octect => this.ipOctects.push(Number.parseInt(octect,10)))
        },
        /**
         * Función que inicializa la ip ingresada por el usuario con su clase, mascara, bits para host, la primera subnet, etc.
         * @returns La ip con su información por defecto
        */
        getIpObject() {
            if(this.ipOctects[0] >= 0 && this.ipOctects[0]<= 127){                //  Si la ip es clase A se inicializan los valores
                this.completeIP = {                                           
                    netClass    : "Clase A",                            //  Asignamos la clase
                    defaultMask : "255.0.0.0",                          //  Asignamos la mascara por defecto
                    maskBits    : "11111111000000000000000000000000",   //  Asiganamos los bits de la mascara
                    hostBits    : 24,                                   //  Los bits para host
                    netBits     : 8,                                    //  Los bits para subredes
                    firstSubNet : [this.ipOctects[0], 0, 0, 0]               //  La primera subred de la direccion
                }
            }
            if(this.ipOctects[0] >= 128 && this.ipOctects[0]<= 191){              //  Si la ip es clase B se inicializan los valores
                this.completeIP = {
                    netClass    : "Clase B",                            //  Asignamos la clase
                    defaultMask : "255.255.0.0",                        //  Asignamos la mascara por defecto
                    maskBits    : "11111111111111110000000000000000",   //  Asiganamos los bits de la mascara
                    hostBits    : 16,                                   //  Los bits para host
                    netBits     : 16,                                   //  Los bits para subredes
                    firstSubNet : [this.ipOctects[0], this.ipOctects[1], 0, 0]    //  La primera subred de la direccion
                }
            }
            if(this.ipOctects[0] >= 192 && this.ipOctects[0]<= 223){       //  Si la ip es clase C se inicializan los valores
                this.completeIP = {
                    netClass    : "Clase C",                            //  Asignamos la clase
                    defaultMask : "255.255.255.0",                      //  Asignamos la mascara por defecto
                    maskBits    : "11111111111111111111111100000000",   //  Asiganamos los bits de la mascara
                    hostBits    : 8,                                    //  Los bits para host
                    netBits     : 24,                                   //  Los bits para subredes
                    firstSubNet : [this.ipOctects[0], this.ipOctects[1], this.ipOctects[2], 0] //  La primera subred de la direccion
                }
            }

        }
    },
}