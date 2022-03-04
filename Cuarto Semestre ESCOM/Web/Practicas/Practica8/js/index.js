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
const saveLocal = document.getElementById("saveLocal");
const saveSession = document.getElementById("saveSession");
const saveCookies = document.getElementById("saveCookies");
const loadLocal = document.getElementById("loadLocal");
const loadSession = document.getElementById("loadSession");
const loadCookies = document.getElementById("loadCookies");

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
  curp,
  comentario,
];
let datosLocal = datos;
let datosSession = datos;

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
  "Curp",
  "Comentario",
];
const lenguajes = [c, cmm, ruby, perl, java, python, otroL];
const lenguajesS = ["c", "cmm", "ruby", "perl", "java", "python", "otroL"];
const pasatiempos = [leer, videojuegos, tv, cine, oC, navegar, netflix];
const pasatiemposS = [
  "leer",
  "videojuegos",
  "tv",
  "cine",
  "oC",
  "navegar",
  "netflix",
];
const mostrarDatos = () => {
  let elements = [];
  let lang = [];
  let pasa = [];
  let cadena = "";

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

saveLocal.addEventListener("click", () => {
  localStorage.setItem("nombre", JSON.stringify(nombre.value));
  localStorage.setItem("aP", JSON.stringify(aP.value));
  localStorage.setItem("aM", JSON.stringify(aM.value));
  localStorage.setItem("calle", JSON.stringify(calle.value));
  localStorage.setItem("no", JSON.stringify(no.value));
  localStorage.setItem("col", JSON.stringify(col.value));
  localStorage.setItem("cp", JSON.stringify(cp.value));
  localStorage.setItem("delega", JSON.stringify(delega.value));
  localStorage.setItem("sexo", JSON.stringify(sexo.value));
  localStorage.setItem("mes", JSON.stringify(mes.value));
  localStorage.setItem("dia", JSON.stringify(dia.value));
  localStorage.setItem("año", JSON.stringify(año.value));
  localStorage.setItem("curp", JSON.stringify(curp.value));
  localStorage.setItem("comentario", JSON.stringify(comentario.value));

  for (let i = 0; i < lenguajes.length; i++) {
    localStorage.setItem(`${lenguajesS[i]}`, lenguajes[i].checked);
  }
  for (let i = 0; i < pasatiempos.length; i++) {
    localStorage.setItem(`${pasatiemposS[i]}`, pasatiempos[i].checked);
  }
});
saveSession.addEventListener("click", () => {
  sessionStorage.setItem("nombre", JSON.stringify(nombre.value));
  sessionStorage.setItem("aP", JSON.stringify(aP.value));
  sessionStorage.setItem("aM", JSON.stringify(aM.value));
  sessionStorage.setItem("calle", JSON.stringify(calle.value));
  sessionStorage.setItem("no", JSON.stringify(no.value));
  sessionStorage.setItem("col", JSON.stringify(col.value));
  sessionStorage.setItem("cp", JSON.stringify(cp.value));
  sessionStorage.setItem("delega", JSON.stringify(delega.value));
  sessionStorage.setItem("sexo", JSON.stringify(sexo.value));
  sessionStorage.setItem("mes", JSON.stringify(mes.value));
  sessionStorage.setItem("dia", JSON.stringify(dia.value));
  sessionStorage.setItem("año", JSON.stringify(año.value));
  sessionStorage.setItem("curp", JSON.stringify(curp.value));
  sessionStorage.setItem("comentario", JSON.stringify(comentario.value));

  for (let i = 0; i < lenguajes.length; i++) {
    sessionStorage.setItem(`${lenguajesS[i]}`, lenguajes[i].checked);
  }
  for (let i = 0; i < pasatiempos.length; i++) {
    sessionStorage.setItem(`${pasatiemposS[i]}`, pasatiempos[i].checked);
  }
});

saveCookies.addEventListener("click", () => {
  document.cookie = `nombre=${JSON.stringify(nombre.value)}`;
  document.cookie = `aP=${JSON.stringify(aP.value)}`;
  document.cookie = `aM=${JSON.stringify(aM.value)}`;
  document.cookie = `calle=${JSON.stringify(calle.value)}`;
  document.cookie = `no=${JSON.stringify(no.value)}`;
  document.cookie = `col=${JSON.stringify(col.value)}`;
  document.cookie = `cp=${JSON.stringify(cp.value)}`;
  document.cookie = `delega=${JSON.stringify(delega.value)}`;
  document.cookie = `sexo=${JSON.stringify(sexo.value)}`;
  document.cookie = `mes=${JSON.stringify(mes.value)}`;
  document.cookie = `dia=${JSON.stringify(dia.value)}`;
  document.cookie = `año=${JSON.stringify(año.value)}`;
  document.cookie = `curp=${JSON.stringify(curp.value)}`;
  document.cookie = `comentario=${JSON.stringify(comentario.value)}`;
  console.log(document.cookie);

    document.cookie = `c=${c.checked}`;
    document.cookie = `cmm=${cmm.checked}`;
    document.cookie = `ruby=${ruby.checked}`;
    document.cookie = `perl=${perl.checked}`;
    document.cookie = `java=${java.checked}`;
    document.cookie = `python=${python.checked}`;
    document.cookie = `otroL=${c.otroL}`;

  for (let i = 0; i < pasatiempos.length; i++) {
    document.cookie = `${pasatiemposS[i]}=${pasatiempos[i].checked}`;
  }
});

loadLocal.addEventListener("click", () => {
  nombre.value = JSON.parse(localStorage.getItem("nombre"));
  aP.value = JSON.parse(localStorage.getItem("aP"));
  aM.value = JSON.parse(localStorage.getItem("aM"));
  calle.value = JSON.parse(localStorage.getItem("calle"));
  no.value = JSON.parse(localStorage.getItem("no"));
  col.value = JSON.parse(localStorage.getItem("col"));
  cp.value = JSON.parse(localStorage.getItem("cp"));
  delega.value = JSON.parse(localStorage.getItem("delega"));
  sexo.value = JSON.parse(localStorage.getItem("sexo"));
  mes.value = JSON.parse(localStorage.getItem("mes"));
  dia.value = JSON.parse(localStorage.getItem("dia"));
  año.value = JSON.parse(localStorage.getItem("año"));
  curp.value = JSON.parse(localStorage.getItem("curp"));
  comentario.value = JSON.parse(localStorage.getItem("comentario"));

  c.checked = JSON.parse(localStorage.getItem("c"));
  cmm.checked = JSON.parse(localStorage.getItem("cmm"));
  ruby.checked = JSON.parse(localStorage.getItem("ruby"));
  perl.checked = JSON.parse(localStorage.getItem("perl"));
  otroL.checked = JSON.parse(localStorage.getItem("otroL"));

  leer.checked = JSON.parse(localStorage.getItem("leer"));
  videojuegos.checked = JSON.parse(localStorage.getItem("videojuegos"));
  tv.checked = JSON.parse(localStorage.getItem("tv"));
  cine.checked = JSON.parse(localStorage.getItem("cine"));
  oC.checked = JSON.parse(localStorage.getItem("oC"));
  navegar.checked = JSON.parse(localStorage.getItem("navegar"));
  netflix.checked = JSON.parse(localStorage.getItem("netflix"));
});

loadSession.addEventListener("click", () => {
  nombre.value = JSON.parse(sessionStorage.getItem("nombre"));
  aP.value = JSON.parse(sessionStorage.getItem("aP"));
  aM.value = JSON.parse(sessionStorage.getItem("aM"));
  calle.value = JSON.parse(sessionStorage.getItem("calle"));
  no.value = JSON.parse(sessionStorage.getItem("no"));
  col.value = JSON.parse(sessionStorage.getItem("col"));
  cp.value = JSON.parse(sessionStorage.getItem("cp"));
  delega.value = JSON.parse(sessionStorage.getItem("delega"));
  sexo.value = JSON.parse(sessionStorage.getItem("sexo"));
  mes.value = JSON.parse(sessionStorage.getItem("mes"));
  dia.value = JSON.parse(sessionStorage.getItem("dia"));
  año.value = JSON.parse(sessionStorage.getItem("año"));
  curp.value = JSON.parse(sessionStorage.getItem("curp"));
  comentario.value = JSON.parse(sessionStorage.getItem("comentario"));

  c.checked = JSON.parse(sessionStorage.getItem("c"));
  cmm.checked = JSON.parse(sessionStorage.getItem("cmm"));
  ruby.checked = JSON.parse(sessionStorage.getItem("ruby"));
  perl.checked = JSON.parse(sessionStorage.getItem("perl"));
  otroL.checked = JSON.parse(sessionStorage.getItem("otroL"));

  leer.checked = JSON.parse(sessionStorage.getItem("leer"));
  videojuegos.checked = JSON.parse(sessionStorage.getItem("videojuegos"));
  tv.checked = JSON.parse(sessionStorage.getItem("tv"));
  cine.checked = JSON.parse(sessionStorage.getItem("cine"));
  oC.checked = JSON.parse(sessionStorage.getItem("oC"));
  navegar.checked = JSON.parse(sessionStorage.getItem("navegar"));
  netflix.checked = JSON.parse(sessionStorage.getItem("netflix"));
});

loadCookies.addEventListener("click", () => {
  let cookies = document.cookie
    .split(";")
    .map((cookie) => cookie.split("="))
    .reduce(
      (acumu, [key, valor]) => ({
        ...acumu,
        [key.trim()]: decodeURIComponent(valor),
      }),
      {}
    )   

  nombre.value = cookies.nombre.substring(1,cookies.nombre.length-1);
  aP.value = cookies.aP.substring(1,cookies.aP.length-1);
  aM.value = cookies.aM.substring(1,cookies.aM.length-1);
  calle.value = cookies.calle.substring(1,cookies.calle.length-1);
  no.value = cookies.no.substring(1,cookies.no.length-1);
  col.value = cookies.col.substring(1,cookies.col.length-1);
  cp.value = cookies.cp.substring(1,cookies.cp.length-1);
  delega.value = cookies.delega.substring(1,cookies.delega.length-1);
  sexo.value = cookies.sexo.substring(1,cookies.sexo.length-1);
  mes.value = cookies.mes.substring(1,cookies.mes.length-1);
  dia.value = cookies.dia.substring(1,cookies.dia.length-1);
  año.value = cookies.año.substring(1,cookies.año.length-1);
  curp.value = cookies.curp.substring(1,cookies.curp.length-1);
  comentario.value = cookies.comentario.substring(1,cookies.comentario.length-1);

  c.checked = cookies.c === 'true' ;
  cmm.checked = cookies.cmm === 'true'
  ruby.checked= cookies.ruby === 'true'
  perl.checked = cookies.perl === 'true'
  java.checked = cookies.java === 'true'
  python.checked = cookies.python === 'true'
  otroL.checked = cookies.otroL === 'true'

  leer.checked = cookies.leer === 'true'
  videojuegos.checked = cookies.videojuegos=== 'true'
  tv.checked = cookies.tv=== 'true'
  cine.checked = cookies.cine=== 'true'
  oC.checked = cookies.oC=== 'true'
  navegar.checked = cookies.navegar=== 'true'
  netflix.checked = cookies.netflix=== 'true'
55010});
