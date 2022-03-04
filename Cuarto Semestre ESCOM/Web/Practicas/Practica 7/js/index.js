let nombre = document.getElementById("nombre");
let aP = document.getElementById("aP");
let aM = document.getElementById("aM");
let calle = document.getElementById("calle");
let no = document.getElementById("no");
let col = document.getElementById("col");
let cp = document.getElementById("cp");
let delega = document.getElementById("delega");
let sexo = document.form.sexo;
let mes = document.getElementById("mes");
let dia = document.getElementById("dia");
let año = document.getElementById("año");
let curp = document.getElementById("curp");
let c = document.getElementById("c");
let cmm = document.getElementById("cmm");
let ruby = document.getElementById("ruby");
let perl = document.getElementById("perl");
let java = document.getElementById("java");
let python = document.getElementById("python");
let otroL = document.getElementById("otroL");
let leer = document.getElementById("leer");
let videojuegos = document.getElementById("videojuegos");
let tv = document.getElementById("tv");
let cine = document.getElementById("cine");
let oC = document.getElementById("oC");
let navegar = document.getElementById("navegar");
let netflix = document.getElementById("netflix");
let comentario = document.getElementById("comentario");

const datos = [
  nombre,
  aP,
  aM,
  calle,
  no,
  col,
  cp,
  delega,
  sexo,
  mes,
  dia,
  año,
  comentario,
];
const datosS = [
  "Nombre",
  "Apellido Paterno",
  "Apellido materno",
  "Calle",
  "Numero",
  "Col",
  "Cp",
  "Delega",
  "Sexo",
  "Mes",
  "Día",
  "Año",
  "Comentario",
];
const lenguajes = [c, cmm, ruby, perl, java, python, otroL];
const pasatiempos = [
  leer,
  videojuegos,
  tv,
  cine,
  oC,
  navegar,
  netflix,
  comentario,
];
const mostrarDatos = () => {
  let elements = [];
  let lang = [];
  let pasa = [];
  let cadena = "";
  // html = `<p>Nombre: ${nombre.value} </p>`
  // alert("Tu nombre es: "+nombre.value+"\n"+"Apellido Paterno: "+aP.value+"\n"+"Apellido Materno: "+aM.value)

  for (let i = 0; i < datos.length; i++) {
    elements.push(datos[i].value);
    cadena += `${datosS[i]}: ${elements[i]} \n`;
  }
  cadena += "Lenguajes de Programacion: \n";
  for (let i = 0; i < lenguajes.length; i++) {
    if (lenguajes[i].checked) {
      lang.push(lenguajes[i].value);
      cadena += `-${lang[i]} \n`;
    }
  }
  console.log(lang);
  cadena += "Pasatiempos: \n";
  for (let i = 0; i < pasatiempos.length; i++) {
    if (pasatiempos[i].checked) {
      pasa.push(pasatiempos[i].value);
      cadena += `-${pasa[i]} \n`;
    }
  }
  console.log(pasa);

  alert(cadena);
};

formulario.addEventListener("submit", (event) => {
  event.preventDefault();
  mostrarDatos();
});
