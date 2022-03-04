const insert = document.getElementById("insert");
const lastButton = document.getElementById("lastButton");
const firstButton = document.getElementById("firstButton");
const createNodeButton = document.getElementById("createNodeButton");
const createButton = document.getElementById("createButton");
const dropButton = document.getElementById("dropButton");
const dropLastButton = document.getElementById("dropLastButton")
const dropSpecificButton = document.getElementById("dropSpecificButton")
const canvas = document.getElementById("canvas");
const canvasContext = canvas.getContext("2d");
const saveButton = document.getElementById("saveButton");
const loadButton = document.getElementById("loadButton");
const cCode = document.getElementById("cCode");
const newButton = document.getElementById("newButton");
const insertSpecificButton = document.getElementById("insertSpecificButton");
const saltButton = document.getElementById("saltButton")
const dropSpecific = document.getElementById("dropSpecific")
const dropValue = document.getElementById("dropValue")
const cCodeCreateNode = document.getElementById("cCodeCreateNode")
const cCodefirstNode = document.getElementById("cCodefirstNode")
const cCodeLastNode = document.getElementById("cCodeLastNode")
const cCodeSpecificNode = document.getElementById("cCodeSpecificNode")
const cCodeDropFirstNode = document.getElementById("cCodeDropFirstNode")
const cCodeDropLastNode = document.getElementById("cCodeDropLastNode")
const cCodeDropSpecificNode = document.getElementById("cCodeDropSpecificNode")
let list = [];
let listNodeValue = 0;
const nodeSize = 25;
const nodewidth = 65;
const nodeHeight = 25;
const canvasWidth = canvas.width;
const canvasHeight = canvas.height;
let x = canvasWidth - nodewidth * 2;
let y = nodeHeight + 10;
let nodeX = 25;
let nodeY = canvasHeight / 2;
let auxY = y;
let auxX = x;
let auxNX = nodeX;
let auxNY = nodeY;
canvasContext.font = "20px Roboto";
let auxi = 0;
let init = 0;
let end = 0;
let specific = 0;

canvasContext.fillStyle = "white";
canvasContext.fill();

const drawNode = () => {

  if (list.length < 2) {
    canvasContext.clearRect(list.length * nodewidth * 5 + 25, 0, canvasWidth, canvasHeight);
    canvasContext.clearRect(x-1 ,y - nodeHeight+12,nodewidth * 3,nodeHeight * 2);
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(listNodeValue, x + 4, y + 20);
    canvasContext.rect(x, y, nodewidth, nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth - 15, y);
    canvasContext.lineTo(x + nodewidth - 15, y + nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 30, y + nodeHeight / 2 + 20);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 21, y + nodeHeight / 2 + 20);
    canvasContext.lineTo(x + nodewidth + 39, y + nodeHeight / 2 + 20);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 24, y + nodeHeight / 2 + 22);
    canvasContext.lineTo(x + nodewidth + 36, y + nodeHeight / 2 + 22);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 27, y + nodeHeight / 2 + 24);
    canvasContext.lineTo(x + nodewidth + 33, y + nodeHeight / 2 + 24);
    canvasContext.stroke();
    canvasContext.closePath();
  } else if (list.length > 0) {
    canvasContext.clearRect(
      list.length * nodewidth * 5 + 25,
      0,
      canvasWidth,
      canvasHeight
    );
    canvasContext.clearRect(
      x - 1,
      y - nodeHeight + 1,
      nodewidth * 3,
      nodeHeight * 2
    );
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(listNodeValue, x + 4, y + 20);
    canvasContext.rect(x, y, nodewidth, nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth - 15, y);
    canvasContext.lineTo(x + nodewidth - 15, y + nodeHeight);
    canvasContext.stroke();
    //arrow begins
    canvasContext.moveTo(x + nodewidth, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 20, y + nodeHeight / 2 - 10);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 20, y + nodeHeight / 2 + 10);
    canvasContext.stroke();
    canvasContext.closePath();
  }
};

const drawStack = (list) => {
  console.log(list.length);
  canvasContext.clearRect(canvasWidth-nodewidth*5,0,canvasWidth,nodeHeight * 3);
  canvasContext.clearRect(0, 0, canvasWidth, canvasHeight);
  nodeY = auxNY;
  nodeX = auxNX;
  for (let listNode of list) {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(listNode, nodeX + 4, nodeY + 20);
    canvasContext.rect(nodeX, nodeY, nodewidth, nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(nodeX + nodewidth - 15, nodeY);
    canvasContext.lineTo(nodeX + nodewidth - 15, nodeY + nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(nodeX + nodewidth, nodeY + nodeHeight / 2);
    canvasContext.lineTo(nodeX + nodewidth + 30, nodeY + nodeHeight / 2);
    canvasContext.stroke();
    if (listNode !== list[list.length - 1]) {

      canvasContext.moveTo(nodeX + nodewidth + 30, nodeY + nodeHeight / 2);
      canvasContext.lineTo(nodeX + nodewidth + 20, nodeY + nodeHeight / 2 - 10);
      canvasContext.moveTo(nodeX + nodewidth + 30, nodeY + nodeHeight / 2);
      canvasContext.lineTo(nodeX + nodewidth + 20, nodeY + nodeHeight / 2 + 10);
    }
    canvasContext.stroke();
    canvasContext.closePath();
    nodeX = nodeX + nodewidth + 30;
  }

  if (list.length > 0) {
    // canvasContext.moveTo(nodeX+nodewidth,nodeY+nodeHeight/2)
    // canvasContext.lineTo(nodeX+nodewidth+30, nodeY+nodeHeight/2)
    // canvasContext.stroke();
    canvasContext.beginPath(); // crearemos un nodo

    canvasContext.moveTo(nodeX, nodeY + nodeHeight / 2);
    canvasContext.lineTo(nodeX, nodeY + nodeHeight / 2);
    canvasContext.stroke();
    canvasContext.moveTo(nodeX, nodeY + nodeHeight / 2);
    canvasContext.lineTo(nodeX, nodeY + nodeHeight / 2 + 20);
    canvasContext.stroke();
    canvasContext.moveTo(nodeX + 11, nodeY + nodeHeight / 2 + 20);
    canvasContext.lineTo(nodeX - 9, nodeY + nodeHeight / 2 + 20);
    canvasContext.stroke();
    canvasContext.moveTo(nodeX + 8, nodeY + nodeHeight / 2 + 22);
    canvasContext.lineTo(nodeX - 6, nodeY + nodeHeight / 2 + 22);
    canvasContext.stroke();
    canvasContext.moveTo(nodeX + 5, nodeY + nodeHeight / 2 + 24);
    canvasContext.lineTo(nodeX - 3, nodeY + nodeHeight / 2 + 24);
    canvasContext.stroke();
    canvasContext.closePath();

    console.log("Nodey Despues " + nodeY);
  }
};

createButton.addEventListener("click", (e) => {
  e.preventDefault();
  listNodeValue = document.getElementById("listNodeValue").value; //obtenemos el valor del nodo
  //   console.log(stackNodeValue);
  lastButton.className = "btn";
  document.getElementById("listNodeValue").className = "hide";
  console.log(list.length);
  cCodeCreateNode.className = "code"
  cCodeDropFirstNode.className = "hide"
  cCodeDropLastNode.className = "hide"
  cCodeDropSpecificNode.className = "hide"
  cCodeLastNode.className = "hide"
  cCodeSpecificNode.className = "hide"
  cCodefirstNode.className = "hide"
  if (list.length < 1) {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(listNodeValue, x + 4, y + 20);
    canvasContext.rect(x, y, nodewidth, nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth - 15, y);
    canvasContext.lineTo(x + nodewidth - 15, y + nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.stroke();

    //down lines
    canvasContext.moveTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 30, y + nodeHeight / 2 + 20);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 21, y + nodeHeight / 2 + 20);
    canvasContext.lineTo(x + nodewidth + 39, y + nodeHeight / 2 + 20);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 24, y + nodeHeight / 2 + 22);
    canvasContext.lineTo(x + nodewidth + 36, y + nodeHeight / 2 + 22);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 27, y + nodeHeight / 2 + 24);
    canvasContext.lineTo(x + nodewidth + 33, y + nodeHeight / 2 + 24);
    canvasContext.stroke();
    canvasContext.closePath();
    console.log("prueba");
  } else {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(listNodeValue, x + 4, y + 20);
    canvasContext.rect(x, y, nodewidth, nodeHeight);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth - 15, y);
    canvasContext.lineTo(x + nodewidth - 15, y + nodeHeight);
    canvasContext.stroke();
    //flecha
    canvasContext.moveTo(x + nodewidth, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 20, y + nodeHeight / 2 - 10);
    canvasContext.stroke();
    canvasContext.moveTo(x + nodewidth + 30, y + nodeHeight / 2);
    canvasContext.lineTo(x + nodewidth + 20, y + nodeHeight / 2 + 10);
    canvasContext.stroke();
    canvasContext.closePath();
    document.getElementById("listNodeValue").value = "";
  }

  //   createButton.disabled = false
  firstButton.className = "btn"
  lastButton.className = "btn"
  specificButton.className = "btn"
  createButton.className = "hide"

});

const insertNode = (position) => {
 
    if(list.length>=position){
      let drawNodeFrame = window.requestAnimationFrame(drawNode);
      nodeX = auxNX;
      for(let i=0; i<position; i++)
        nodeX = nodeX + nodewidth + 30
      let drawNodeInterval = setInterval(() => {
        if (x != nodeX) x = x - 1;
        else if (y != nodeY) y = y + 1;
        if (x == nodeX && y == nodeY) {
          window.cancelAnimationFrame(drawNodeFrame);

          x = auxX;
          y = auxY;
          drawStack(list);

          clearInterval(drawNodeInterval);

        } else {
          drawNodeFrame = window.requestAnimationFrame(drawNode);
        }
      }, 0.1);
    
      list.splice(position, 0, listNodeValue)
      createButton.disabled = false;
      dropButton.disabled = false;
      document.getElementById("listNodeValue").className = "hide";
      createNodeButton.disabled = false;
    }
  
};


saveButton.addEventListener("click", (e) => {
  e.preventDefault();
  localStorage.setItem("List", JSON.stringify(list));
});

loadButton.addEventListener("click", (e) => {
  e.preventDefault();
  if (localStorage.getItem("List")) {
    list = JSON.parse(localStorage.getItem("List"));
    drawStack(list);
    saveButton.className = "btn";
    createButton.className = "hide";
    dropButton.className = "btn";
    createNodeButton.className = "btn";
    document.getElementById("listNodeValue").className = "hide";
    newButton.className = "hide";
    dropButton.disabled = false;
    dropLastButton.className = "btn"
    dropSpecificButton.className = "btn"
    // firstButton.className = "btn"
    // lastButton.className = "btn"
    // specificButton.className = "btn"
  }
});
newButton.addEventListener("click", (e) => {
  e.preventDefault();
  document.getElementById("listNodeValue").className = "hide";
  newButton.className = "hide"
  saveButton.className = "btn"
  createNodeButton.className = "btn"
});
createNodeButton.addEventListener("click", (e) => {
  e.preventDefault();
  canvasContext.clearRect(canvasWidth-nodewidth*5,0,canvasWidth,nodeHeight * 3);
  if (list.length > 5) {
    alert("La pila esta llena, no puedes agregar más nodos");
    return;
  }
  createButton.className = "btn"
  document.getElementById("listNodeValue").className = "";
  dropLastButton.className = "btn"
  dropSpecificButton.className = "btn"
  dropButton.className = "btn"
  lastButton.className = "btn";
  createNodeButton.className = "btn"
  lastButton.className = "hide";
  dropButton.disable = true;
  dropLastButton.disable = true
  dropSpecificButton.disable = true

});



//insert buttons
firstButton.addEventListener("click", (e) => {
  e.preventDefault();
  init = 0;
  insertNode(init)
  cCodeCreateNode.className = "hide"
  cCodeDropFirstNode.className = "hide"
  cCodeDropLastNode.className = "hide"
  cCodeDropSpecificNode.className = "hide"
  cCodeLastNode.className = "hide"
  cCodeSpecificNode.className = "hide"
  cCodefirstNode.className = "code"
  firstButton.className = "hide"
  lastButton.className = "hide"
  specificButton.className = "hide"
  insertSpecificButton.className = "hide"
  saltButton.className = "hide"
});
lastButton.addEventListener("click", (e) => {
  e.preventDefault();
  final = list.length;
  insertNode(final)
  cCodeCreateNode.className = "hide"
  cCodeDropFirstNode.className = "hide"
  cCodeDropLastNode.className = "hide"
  cCodeDropSpecificNode.className = "hide"
  cCodeLastNode.className = "code"
  cCodeSpecificNode.className = "hide"
  cCodefirstNode.className = "hide"
  firstButton.className = "hide"
  lastButton.className = "hide"
  specificButton.className = "hide"
  insertSpecificButton.className = "hide"
  saltButton.className = "hide"

});
insertSpecificButton.addEventListener("click", (e) => {
  e.preventDefault();
  let posicion = document.getElementById("saltButton").value -1;
  if(posicion>list.length){
    alert("No se peude insertar en esa posición")
    return
  }
  insertNode(posicion)
  cCodeCreateNode.className = "hide"
  cCodeDropFirstNode.className = "hide"
  cCodeDropLastNode.className = "hide"
  cCodeDropSpecificNode.className = "hide"
  cCodeLastNode.className = "hide"
  cCodeSpecificNode.className = "code"
  cCodefirstNode.className = "hide"
  insertSpecificButton.className = "hide"
  saltButton.className = "hide"
  firstButton.className = "hide"
  lastButton.className = "hide"
  specificButton.className = "hide"

  
});
specificButton.addEventListener("click", (e) => {
  e.preventDefault()
  saltButton.className = ""
  insertSpecificButton.className = "btn"
  firstButton.className = "hide"
  lastButton.className = "hide"
  specificButton.className = "hide"

})

//drop buttons

dropButton.addEventListener("click", (e) => {
  e.preventDefault();
  let listAux = list;
  if (listAux.length == 0) alert("La lista esta vacía. No hay nada que sacar");
  else {
    listAux.shift();
    // localStorage.setItem("Stack", stackAux)
    drawStack(listAux);
    cCodeCreateNode.className = "hide"
    cCodeDropFirstNode.className = "code"
    cCodeDropLastNode.className = "hide"
    cCodeDropSpecificNode.className = "hide"
    cCodeLastNode.className = "hide"
    cCodeSpecificNode.className = "hide"
    cCodefirstNode.className = "hide"
  }
});

dropLastButton.addEventListener("click", (e) => {
  e.preventDefault();
  let listAux = list;
  if (listAux.length == 0) alert("La lista esta vacía. No hay nada que sacar");
  else {
    listAux.pop();
    drawStack(listAux);
    cCodeCreateNode.className = "hide"
    cCodeDropFirstNode.className = "hide"
    cCodeDropLastNode.className = "code"
    cCodeDropSpecificNode.className = "hide"
    cCodeLastNode.className = "hide"
    cCodeSpecificNode.className = "hide"
    cCodefirstNode.className = "hide"
  }
})
dropSpecificButton.addEventListener("click", (e) => {
  e.preventDefault()
  if (list.length == 0) alert("La lista esta vacía. No hay nada que sacar");
  else {
    dropSpecific.className = "btn"
    dropValue.className = ""
    dropButton.className = "hide"
    dropLastButton.className = "hide"
  }
})
dropSpecific.addEventListener("click", (e) => {
  e.preventDefault()
  let listAux = list;
  let dropVal = document.getElementById("dropValue").value
  if(dropVal > list.length){
    alert("No existe esa posición")
    return
  }
  listAux.splice(dropVal-1, 1);
  drawStack(listAux);
  cCodeCreateNode.className = "hide"
  cCodeDropFirstNode.className = "hide"
  cCodeDropLastNode.className = "hide"
  cCodeDropSpecificNode.className = "code"
  cCodeLastNode.className = "hide"
  cCodeSpecificNode.className = "hide"
  cCodefirstNode.className = "hide"
  dropSpecific.className ="hide"
  dropValue.className = "hide"
  dropButton.className ="btn"
  dropLastButton.className = "btn"
  dropSpecificButton.className = "btn"
})
