

/**
 * @param {array} conjunto Conjunto que contiene los valores
 * @param {int} n Longitud del conjunto
 * @param {int} sum Suma a verificar
 * @returns True si existe una suma, false si no
*/
const esSumaConjunto = (conjunto, n, sum) =>{

    //* Casos base
    if( sum == 0 )
        return true
    if( sum < 0 || (n == 0 && sum != 0) )
        return false


    //* Si el último elemento es mayor a la suma que estamos verificando se ignora
    if( conjunto[n-1] > sum )
        return esSumaConjunto(conjunto, n-1, sum)

    
    //* La primera opciòn es no incluirlo, la segunda es incluirlo
    return esSumaConjunto(conjunto, n-1, sum) || esSumaConjunto(conjunto, n-1, sum - conjunto[n-1])

}

let conjunto = [2,6,4,8]
let sum = 10
let n = conjunto.length

esSumaConjunto(conjunto, n, sum) ? console.log("True") : console.log("False");

