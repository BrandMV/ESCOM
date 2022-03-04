export default{
    methods: {
        /**
         * Función que calcula el salto para ir calculando las subredes de la dirección requerido de acuerdo a los hosts, subredes o prefijo
         * @param {*} prefix El prefijo de la red
         * @param {*} newMask La nueva mascara calculada anteriormente
         * @param {*} netClass La clase de la dirección Ip
         * @returns Retorna el salto para cada subred
        */
        hopFunc(){
            let hop                                 
            if(this.completeIP.netClass == "Clase A")                       //  Si la clase es A:
                if (this.prefixSubnet >= 8 && this.prefixSubnet <= 16){           
                    hop = 256 - this.newMaskSubnet[1]                      //  Si el prefijo esta entre 8 y 16 el salto será de 256 menos el segundo octeto     
                    this.octectToModify = 1                               //  El octeto a modificar sera el segundo
                } else if(this.prefixSubnet >= 17 && this.prefixSubnet <=24){         //  Si el prefijo esta entre 17 y 24:
                    hop = 256 - this.newMaskSubnet[2]                          //  El salto sera 256 - el octeto 3 de la red
                    this.octectToModify = 2                              //  El octeto a modificar sera el 3
                } else hop = 256 - this.newMaskSubnet[3]                   //  En otro caso el salto sera 256 menos el valor del ultimo octeto
        
            if(this.completeIP.netClass == "Clase B")                       //  Si la clase es B:
                if (this.prefixSubnet >= 16 && this.prefixSubnet <= 24){              //Si el octeto esta entre 16 y 24
                    hop = 256 - this.newMaskSubnet[2]                          //  El salto sera 256 - el octeto 3 de la red
                    this.octectToModify = 2                              //  El octeto a modificar sera el 3
                } else hop = 256 - this.newMaskSubnet[3]               //  En otro caso el salto sera 256 menos el valor del ultimo octeto
        
            if(this.completeIP.netClass == "Clase C")                       //  Si la clase es C:
                hop = 256 - this.newMaskSubnet[3]                          //  En otro caso el salto sera 256 menos el valor del ultimo octeto       
        
            return hop                                      //Retornamos el salto resultante
        }
    },
}