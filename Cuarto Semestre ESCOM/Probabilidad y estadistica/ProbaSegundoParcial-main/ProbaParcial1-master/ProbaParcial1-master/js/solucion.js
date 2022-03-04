let preguntaUno;
let preguntaDos;
let preguntaTres;
let bandera=0;

function solucionar(){
    total = document.getElementById("totalGalletas").value;
    chocolate = document.getElementById("totalGalletasChoc").value;
    otras = total - chocolate;
    if(otras<0){
        Swal.fire({
            icon: 'error',
            title: 'Ingresa bien los datos'  
        })
        bandera=1;
    }
    else{

        console.log("Datos correctos: " + total + " " + chocolate + " " + otras);

        preguntaUno = ( factorial(chocolate) / ( factorial(chocolate-2) * factorial(2) ) ) / ( factorial(total) / ( factorial(total-2) * factorial(2) ) )
        console.log(preguntaUno);
    
        preguntaDos = (chocolate / total) * (otras / (total-1));
        console.log(preguntaDos);
    
        preguntaTres = ( factorial(otras) / ( factorial(otras-2) * factorial(2) ) )  / ( factorial(total) / ( factorial(total-2) * factorial(2) ) );
        console.log(preguntaTres);
    }
       


}
const factorial = (num) =>{
    let fac=1;
    for(i=1; i<=num; i++)
        fac = fac * i;

    return fac
}

const formulario = document.getElementById("formsol");
formulario.addEventListener('submit', (event) => {
    bandera=0;
    event.preventDefault();
    solucionar()
    if(bandera===0){
        Swal.fire({
            icon: 'success',
            title: 'Resultados',
            html:  `<p>La probabilidad de que las dos sean de chocolate es de: ${preguntaUno}</p>
                    <p>La probabilidad de que la primera sea de chocolate y la segunda de otro sabor es de: ${preguntaDos}</p>
                    <p>La probabilidad de que ambas sean de otro sabor ${preguntaTres}</p>`
            
        })
    }
    
});
