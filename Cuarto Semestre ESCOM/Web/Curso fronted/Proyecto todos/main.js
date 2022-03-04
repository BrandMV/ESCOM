// variables 
const formulario = document.querySelector('#formulario');
const text = document.querySelector('#texto');
const lista = document.querySelector('#lista');
const tareas = []
const materia = document.querySelector('#materia')
// funciones
const agregarTarea = () => {
    const nuevaTarea = text.value
    const nuevaMateria = materia.value
    if(nuevaTarea && nuevaMateria && nuevaMateria.length && nuevaTarea.length > 0){
        tareas.push({tarea: nuevaTarea, materia: nuevaMateria})
    }
    text.value=''
    materia.value=''
  
}

const mostrarTareas = () => {
    let html = ""
    tareas.forEach((tarea, id) => { //toma los elementos uno por uno
        html += generarHTML(tarea, id)
        //console.log(tarea);
        //console.log(id);
    })
    //con const: const html = tareas.map((tarea, id) => generarHTML(tarea, id)).join(' ')
    //console.log(html);
    lista.innerHTML = html
}

const generarHTML = ({tarea, materia}, id) => {

    return `<li id="t${id}">tarea: ${tarea}, materia: ${materia} <span onclick="eliminarTarea(${id})">X</span></li>`
}

const eliminarTarea = (id) => {
    tareas.splice(id, 1)
    mostrarTareas()
}
// event listeners
formulario.addEventListener('submit',(event) => {
    event.preventDefault()
    agregarTarea()
    mostrarTareas()
})

const finish = () => {
    setTimeout(() => {
        console.log("Pasaron 2 seg");
    }, 2000); //cuando pasen 2000 milisegundos haz lo de adentro
}

const intervalo = () => {
    setInterval(() => {
        alert("paso cada dos segundos")
    }, 2000);
}
//objeto que representa la terminacion o el fracaso de una operacion asincrona
    //pending: estado incial
    //fulfilled: la ejecucion es completa
    //Rejected: se devuelve un error

/*

async / await

es la forma mas moderna de manejar procesos asincronos
si hay un error usamos el try catch


 */