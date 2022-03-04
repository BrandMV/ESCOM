const enqueueButton = document.getElementById("enqueueButton");
const createNodeButton = document.getElementById("createNodeButton")
const createButton = document.getElementById("createButton");
const dequeueButton = document.getElementById("dequeueButton");
const canvas = document.getElementById("canvas");
const canvasContext = canvas.getContext("2d");
const saveButton = document.getElementById("saveButton");
const loadButton = document.getElementById("loadButton");
const cCode = document.getElementById("cCode");
const newButton = document.getElementById("newButton");
const cCodeEnqueueNode = document.getElementById("cCodeEnqueueNode")
const cCodeDequeueNode = document.getElementById("cCodeDequeueNode")
const cCodeCreateNode = document.getElementById("cCodeCreateNode")
let queue = [];
let queueNodeValue = 0;
const nodeSize = 25;
const canvasWidth = canvas.width;
const canvasHeight = canvas.height;
let x = canvasWidth - nodeSize * 2;
let y = nodeSize + 10;
let nodeX = 25;
let nodeY = canvasHeight / 2;
let aux = y;
canvasContext.font = "20px Roboto";
let auxi = 0;

canvasContext.fillStyle = "white";
canvasContext.fill();

const drawNode = () => {
  // canvasContext.fillText("", nodeX - 18, nodeY + 10);

  // console.log("la x: "+x+" la y: "+y);
  canvasContext.clearRect(
    queue.length * nodeSize*3  + 25,
    0,
    canvasWidth,
    canvasHeight
  );
  canvasContext.clearRect(x-nodeSize-2, y-nodeSize-6, nodeSize*3+10, nodeSize*2+8);

  canvasContext.beginPath(); // crearemos un nodo
  canvasContext.fillStyle = "black";
  canvasContext.fillText(queueNodeValue, x - 15, y + 8);
  canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
  canvasContext.stroke();
  canvasContext.closePath();

  canvasContext.beginPath(); // crearemos un nodo

  canvasContext.moveTo(x + 25, y);
  canvasContext.lineTo(x + 50, y);
  canvasContext.lineTo(x + 40, y - 10);
  canvasContext.moveTo(x + 50, y);
  canvasContext.lineTo(x + 40, y + 10);
  canvasContext.stroke();
  canvasContext.closePath();
};

const drawStack = (queue) => {
  console.log(queue.length);
  canvasContext.clearRect(0, 0, canvasWidth, canvasHeight);
  nodeY = canvasHeight / 2;
  nodeX = 25;

  for (let queueNode of queue) {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(queueNode, nodeX - 15, nodeY + 8);
    canvasContext.arc(nodeX, nodeY, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
    canvasContext.closePath();

    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.strokeStyle = "black";

    canvasContext.moveTo(nodeX + 25, nodeY);
    canvasContext.lineTo(nodeX + 50, nodeY);
    canvasContext.lineTo(nodeX + 40, nodeY - 10);
    canvasContext.moveTo(nodeX + 50, nodeY);
    canvasContext.lineTo(nodeX + 40, nodeY + 10);
    canvasContext.stroke();
    canvasContext.closePath();
    nodeX = nodeX + nodeSize * 2 + 25;

    console.log("Nodey Despues " + nodeY);
  }
};

createButton.addEventListener("click", (e) => {
 
  e.preventDefault();
  cCodeCreateNode.className = "code"
  cCodeDequeueNode.className = "hide"
  cCodeEnqueueNode.className = "hide"
  queueNodeValue = document.getElementById("queueNodeValue").value; //obtenemos el valor del nodo
  //   console.log(stackNodeValue);
  enqueueButton.className = "btn";
  document.getElementById("queueNodeValue").className = "hide";

  if (queue.length > 7) {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(queueNodeValue, x - 15, y + 8);
    canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
    canvasContext.closePath();
    document.getElementById("queueNodeValue").value = "";
    //   createButton.disabled = false
    dequeueButton.disabled = true;
    createButton.disabled = true;
  } else {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(queueNodeValue, x - 15, y + 8);
    canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
    canvasContext.closePath();

    canvasContext.beginPath(); // crearemos un nodo

    canvasContext.moveTo(x + 25, y);
    canvasContext.lineTo(x + 50, y);
    canvasContext.lineTo(x + 40, y - 10);
    canvasContext.moveTo(x + 50, y);
    canvasContext.lineTo(x + 40, y + 10);
    canvasContext.stroke();
    canvasContext.closePath();
    document.getElementById("queueNodeValue").value = "";
    //   createButton.disabled = false
    dequeueButton.disabled = true;
    createButton.disabled = true;
    enqueueButton.disabled = false;
    createButton.className = "hide"
  }
});

enqueueButton.addEventListener("click", (e) => {
  e.preventDefault();
  cCodeCreateNode.className = "hide"
  cCodeDequeueNode.className = "hide"
  cCodeEnqueueNode.className = "code"
  //   let drawNodeFrame = window.requestAnimationFrame(drawNode);
  let drawNodeInterval = setInterval(() => {
    if (x != nodeX) x = x - 1;
    else if (y != nodeY) y = y + 1;
    if (x == nodeX && y == nodeY) {
      //   canvasContext.clearRect(600,0, canvasWidth, canvasHeight)
      window.cancelAnimationFrame(drawNodeFrame);
      drawStack(queue);
      clearInterval(drawNodeInterval);
      x = canvasWidth - nodeSize * 2;
      y = nodeSize + 10;
    } else {
      drawNodeFrame = window.requestAnimationFrame(drawNode);
    }
  }, 0.1);

  //   console.log("NodeY: "+nodeY);
  //   console.log("y: "+y);
  //   console.log("stack value: "+stackNodeValue);
  queue.push(queueNodeValue);
  createButton.disabled = false;
  enqueueButton.disabled = true;
  dequeueButton.disabled = false;
  document.getElementById("queueNodeValue").className = "hide";
  enqueueButton.className = "hide";
  createNodeButton.disabled = false


});

dequeueButton.addEventListener("click", (e) => {
  e.preventDefault();
  cCodeCreateNode.className = "hide"
  cCodeDequeueNode.className = "code"
  cCodeEnqueueNode.className = "hide"
  let queueAux = queue;
  if (queueAux.length == 0) alert("La cola esta vacía. No hay nada que sacar");
  else {
    queueAux.shift();
    // localStorage.setItem("Stack", stackAux)
    drawStack(queueAux);
  }
});

saveButton.addEventListener("click", (e) => {
  e.preventDefault();
  localStorage.setItem("Queue", JSON.stringify(queue));
});

loadButton.addEventListener("click", (e) => {
  e.preventDefault();
  if (localStorage.getItem("Queue")) {
    queue = JSON.parse(localStorage.getItem("Queue"));
    drawStack(queue);
    saveButton.className = "btn";
    createButton.className = "hide";
    dequeueButton.className = "btn";
    createNodeButton.className = "btn"
    document.getElementById("queueNodeValue").className = "hide";
    newButton.className = "hide";
    dequeueButton.disabled = false
  }
});
newButton.addEventListener("click", (e) => {
  e.preventDefault();
  newButton.className = "hide";
  loadButton.className = "btn";
  dequeueButton.className = "btn";
  createButton.className = "hide";
  saveButton.className = "btn";
  dequeueButton.disabled = true
  createNodeButton.className = "btn"
  document.getElementById("queueNodeValue").className = "hide";
});
createNodeButton.addEventListener("click", (e) => {
    e.preventDefault()
    canvasContext.clearRect(canvasWidth-nodeSize*3, 0, canvasWidth, nodeSize*3)
    if (queue.length > 7) {
        alert("La pila esta llena, no puedes agregar más nodos");
        return;
      }
  document.getElementById("queueNodeValue").className = "";
  enqueueButton.className = "btn"
  createNodeButton.disabled = true
  createButton.className = "btn"
  enqueueButton.className = "hide"
  dequeueButton.disable = true
    
})
