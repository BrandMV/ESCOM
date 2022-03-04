export default{
    methods: {
        /**
         * Función que calcula una constante que nos servirá para el calculo de las nuevas submascaras de las redes
         * @returns Retorna la cantidad total de los 4 bytes que tiene la red
        */
        auxSubmaskCalc(){
            let resAux = 0;                    //  Inicializamos en 0
            for(let i=0;i<32;i++)               //  Ciclo hasta el número de bits de la red
                resAux = resAux + Math.pow(2,i)   //  Vamos sumando de acuerdo a la potencia de i
            
            this.res = resAux                      //  Retornamos el resultado
        },
        /**
         * Función que calcula la nueva mascara 
         * @param expo El exponente al que esta elevado 
         * @param res  Resultado obtenido de la función auxSubmaskCalc
         * @returns la nueva mascara de la red
        */
        getNewMask(expo){
             /*
                La nueva mascara esta obtenida en una sola línea, se desglozará para mejor entendimiento
                (res << expo) >>> 0 Primero se realiza un corrimiento de bits a la izquierda de acuerdo al exponente
                        Posteriormente un ocrrimiento sin signo a la derecha para obtener la cadena de bits completa
                        de la mascara
                .toString(2) Pasamos a binario la cantidad obtenida con las operaciones anteriores
                .match()    Tomamos 8 bits de la cadena de 32 bits
                .map()      Recorremos de 8 en 8 los bits de la mascara para convertirlos en un entero decimal
            */
            return ( ( ( this.res << expo ) >>> 0).toString(2)).match(/.{1,8}/g).map(byte => parseInt(byte, 2)) 
        },
    },
}