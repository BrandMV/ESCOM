export default{
    methods: {
        /**
         * Función que calcula el prefijo de la nueva submascara
         * @param powSubnet Es la potencia a la que esta elevada la subred
         * @param netBits   Los bits de red de la dirección
         * @returns El prefijo de la nueva submascara de la red
         */
        prefixFunc(){ return this.completeIP.netBits + this.expoSubnets },     //Se suman los bits de red con la potencia de la subred

    },
}