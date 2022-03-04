/**
 * @param {array} conjunto Conjunto que contiene los valores
 * @param {int} n Longitud del conjunto
 * @param {int} sum Suma a verificar
 * @returns True si existe una suma, false si no
*/
const esSumaConjunto = (conjunto, n, sum) =>{

    //*Se crea la tabla inicializando los valores subconjunto[n+1][sum+1]
    let subconjunto = new Array(n + 1)
    for(let i=0;i < n + 1;i++){
        subconjunto[i] = new Array(n + 1)
        for(let j=0; j< sum+1; j++)
            subconjunto[i][j] = 0
    }

    //*Si la suma a buscar es 0, se regresa true
    for(let i=0; i<= n; i++)
        subconjunto[i][0] = true

    //*Si la suma no es 0, pero el conjunto es vacio se regresa false
    for(let i = 1; i <= sum; i++)
        subconjunto[0][i] = false

    //*Se llena la tabla recorriendo la suma y los elementos del conjunto
    for(let i=1; i <= n; i++){
        for(let j=1; j <= sum; j++){
            //*Si el elemento actual es mayor al valor actual de la suma copiamos el valor del caso anterior
            if(j < conjunto[i - 1])
                subconjunto[i][j] = subconjunto[i-1][j]
            //*Si el valor actual de la suma es mayor que el iesimo elemento
            //*]hacemos or entre los casos previos y el caso de j-valor de suma actual
            if(j >= conjunto[i-1])
                subconjunto[i][j] = subconjunto[i-1][j] || subconjunto[i-1][j-conjunto[i-1]]
        }
    }

    return subconjunto[n][sum]
}

let conjunto = [3,6,4,8]
let sum = 10
let n = conjunto.length

esSumaConjunto(conjunto, n, sum) ? console.log("True") : console.log("False");



