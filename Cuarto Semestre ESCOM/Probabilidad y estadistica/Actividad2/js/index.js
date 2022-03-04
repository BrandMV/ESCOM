let people = 0
let probability = 0
const a = document.getElementById("a")
const b = document.getElementById("b")
const c = document.getElementById("c")
const probaValue = document.getElementById("probaValue")
const peopleValue = document.getElementById("peopleValue")
let resA = 0
let resB = 0

const probA = (people, probability) =>{
    resA = probability * Math.pow(1-probability, people)
}

const probB = () =>{
    resB = (1/probability) - 1
}

a.addEventListener("click", (e) => {
    e.preventDefault();
    people = parseFloat(peopleValue.value)
    probability = parseFloat(probaValue.value)
    if(probability > 1){
      alert("La probabildiad debe ser menor a 1")
      return
    }

    probA(people, probability)
   
      Swal.fire({
        icon: "success",
        title: "Resultado a)",
        html: ` <p>P(X=${people})=(${probability})(1-${probability})^${people}</p>
                <p>La probabilidad de que una serie de 15 personas cruce sin problemas es de: ${resA}</p>`,
      });
    
})

b.addEventListener("click", (e) => {
    e.preventDefault();
    probB()
   
      Swal.fire({
        icon: "success",
        title: "Resultado a)",
        html: `<p>μ=(1/${probability}) - 1</p>
              <p>El número esperado de personas que pasaran antes de que detengan a una es de: ${resB}</p>`,
      });
    
})

c.addEventListener("click", (e) => {
    e.preventDefault();
    probB()
   
      Swal.fire({
        icon: "success",
        title: "Resultado a)",
        html: `<p>Pertenece a una distribución geométrica</p>`,
      });
    
})