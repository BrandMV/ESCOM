const cards = document.getElementById('cards')

const llamarAPI = async () => {
    const res = await fetch('https://rickandmortyapi.com/api/character/'); //Fetch funcion s dejavascript que trae informacion de APIS
    const data = await res.json() //convierte lo de la api a objetos que puede entender js
    const personajes = data.results

    const result = personajes
        .map((personaje) => {
             return generarTarjeta(personaje)
        })
        .join(' ')

        cards.innerHTML = result
}

const generarTarjeta = ({image, name, status, species, gender}) => {
    return `
   
    <div class="contenedor">
        <img src="${image}" alt="${name}">
            <div id="datos">
                <h1>${name}</h1>
                <ul>
                    <li>Status: ${status}</li>
                    <li>Specie: ${species}</li>
                    <li>Gender: ${gender}</li>
                </ul>
            </div>
    </div>

    `
}

llamarAPI()
