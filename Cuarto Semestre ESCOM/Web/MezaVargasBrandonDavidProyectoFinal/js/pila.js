const createNodeButton = document.getElementById("createNodeButton")
const pushButton = document.getElementById("pushButton");
const createButton = document.getElementById("createButton");
const popButton = document.getElementById("popButton");
const canvas = document.getElementById("canvas");
const canvasContext = canvas.getContext("2d");
const saveButton = document.getElementById("saveButton")
const loadButton = document.getElementById("loadButton")
const cCode = document.getElementById("cCode")
const newButton = document.getElementById("newButton")
const cCodeCreateNode = document.getElementById("cCodeCreateNode")
const cCodePopNode = document.getElementById("cCodePopNode")
const cCodeInsertNode = document.getElementById("cCodeInsertNode")
let stack = [];
let stackNodeValue = 0;
const nodeSize = 25;
const canvasWidth = canvas.width;
const canvasHeight = canvas.height;
let x = canvasWidth / 2;
let y = nodeSize + 10;
let nodeX = x;
let nodeY = canvasHeight - 35;
let aux = y;
canvasContext.font = "20px Roboto";
let auxi=0;
let auxNX
let auxNY

canvasContext.fillStyle='white'
canvasContext.fill()

const drawNode = () => {
    // canvasContext.fillText("", nodeX - 18, nodeY + 10);


  if (stack.length < 2) {
    // console.log("la x: "+x+" la y: "+y);
    canvasContext.clearRect(400, y-nodeSize-6, canvasWidth, nodeSize*2+6);
    canvasContext.clearRect(x-nodeSize-1, y-nodeSize-6, nodeSize*2+5, nodeSize*2+6);
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";

    canvasContext.fillText(stackNodeValue, x - 18, y + 10);
    canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
  } else {
       // console.log("la x: "+x+" la y: "+y);
    canvasContext.clearRect(0, y-nodeSize+20, canvasWidth, nodeSize*2+6);
      canvasContext.clearRect(x-nodeSize-1, y-nodeSize-6, nodeSize*2+5, nodeSize*2+6);
    canvasContext.beginPath(); 
    canvasContext.fillStyle = "black";

    canvasContext.fillText(stackNodeValue, x - 18, y + 10);
    canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
    canvasContext.moveTo(x, y + 25);
    canvasContext.lineTo(x, y + 50);
    canvasContext.lineTo(x - 10, y + 40);
    canvasContext.moveTo(x, y + 50);
    canvasContext.lineTo(x + 10, y + 40);
    canvasContext.stroke();

  }

};

const drawStack = (stack) => {
    
  if (stack.length < 2) {
    console.log(stack.length);
    canvasContext.clearRect(0, 0, canvasWidth, canvasHeight);
    nodeY = canvasHeight - 35;

    for (let stackNode of stack) {
      canvasContext.beginPath(); // crearemos un nodo
      canvasContext.fillStyle = "black";
      canvasContext.fillText(stackNode, nodeX - 18, nodeY + 10);
      canvasContext.arc(nodeX, nodeY, nodeSize, 0, Math.PI * 2, false);
      canvasContext.stroke();

      canvasContext.closePath();

      nodeY = nodeY - nodeSize * 2 -25;
      console.log("Nodey Despues " + nodeY);
    }
  } else {
    console.log(stack.length);
    canvasContext.clearRect(0, 0, canvasWidth, canvasHeight);
    nodeY = canvasHeight - 35;
    for (let stackNode of stack) {
      canvasContext.beginPath(); // crearemos un nodo
      canvasContext.fillStyle = "black";
      canvasContext.fillText(stackNode, nodeX - 18, nodeY + 10);
      canvasContext.arc(nodeX, nodeY, nodeSize, 0, Math.PI * 2, false);
      canvasContext.stroke();
      canvasContext.moveTo(nodeX, nodeY + 25);
      canvasContext.lineTo(nodeX, nodeY + 50);
      canvasContext.lineTo(nodeX - 10, nodeY + 40);
      canvasContext.moveTo(nodeX, nodeY + 50);
      canvasContext.lineTo(nodeX + 10, nodeY + 40);
      canvasContext.stroke();
      canvasContext.closePath();
      canvasContext.beginPath(); // crearemos un nodo
      canvasContext.strokeStyle = "white";

      canvasContext.moveTo(x, canvasHeight - 10);
      canvasContext.lineTo(x, canvasHeight + 15);
      canvasContext.lineTo(x - 10, canvasHeight + 5);
      canvasContext.moveTo(x, canvasHeight + 15);
      canvasContext.lineTo(x + 10, canvasHeight + 5);
      canvasContext.stroke();
      canvasContext.closePath();
      canvasContext.strokeStyle = "black";

      nodeY = nodeY - nodeSize * 2 - 25;
      console.log("Nodey Despues " + nodeY);
    }
  }
};

createButton.addEventListener("click", (e) => {
   
  e.preventDefault();

  stackNodeValue = document.getElementById("stackNodeValue").value; //obtenemos el valor del nodo
  //   console.log(stackNodeValue);
  pushButton.className="btn"
  createButton.className= "hide"
  document.getElementById("stackNodeValue").className="hide"
  cCodeCreateNode.className="code"
  cCodeInsertNode.className="hide"
  cCodePopNode.className="hide"

  console.log(stack.length);
  if (stack.length < 1) {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(stackNodeValue, x - 15, y + 8);
    canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
    canvasContext.closePath();
    document.getElementById("stackNodeValue").value = "";
    //   createButton.disabled = false
    popButton.disabled = true;
    createButton.disabled = true;
  } else {
    canvasContext.beginPath(); // crearemos un nodo
    canvasContext.fillStyle = "black";
    canvasContext.fillText(stackNodeValue, x - 15, y + 8);
    canvasContext.arc(x, y, nodeSize, 0, Math.PI * 2, false);
    canvasContext.stroke();
    canvasContext.moveTo(x, y + 25);
    canvasContext.lineTo(x, y + 50);
    canvasContext.lineTo(x - 10, y + 40);
    canvasContext.moveTo(x, y + 50);
    canvasContext.lineTo(x + 10, y + 40);
    canvasContext.stroke();
    canvasContext.closePath();
    document.getElementById("stackNodeValue").value = "";
    //   createButton.disabled = false
    popButton.disabled = true;
    createButton.disabled = true;
    pushButton.disabled = false

  }


});

pushButton.addEventListener("click", (e) => {
  e.preventDefault();
  cCodePopNode.className="hide"
  cCodeInsertNode.className = "code"
  cCodeCreateNode.className = "hide"
  let drawNodeFrame = window.requestAnimationFrame(drawNode);
  let drawNodeInterval = setInterval(() => {
    if (x != nodeX) x = x - 1;
    else if (y != nodeY) y = y + 1;
    if (x == nodeX && y == nodeY) {
      canvasContext.clearRect(600,0, canvasWidth, canvasHeight)

     drawStack(stack);
      window.cancelAnimationFrame(drawNodeFrame);

  
      clearInterval(drawNodeInterval);
      x = canvasWidth / 2;
      y = nodeSize + 10;
     

    } else {
      drawNodeFrame = window.requestAnimationFrame(drawNode);
     
    }
  }, 2);
  
  //   console.log("NodeY: "+nodeY);
  //   console.log("y: "+y);
  //   console.log("stack value: "+stackNodeValue);
  stack.push(stackNodeValue);
  createButton.disabled = false;
  pushButton.disabled = true
  popButton.disabled = false
  document.getElementById("stackNodeValue").className="hide"
  pushButton.className="hide"
  createNodeButton.disabled = false

  
});

popButton.addEventListener("click", (e) => {
  cCodeCreateNode.className = "hide"
  cCodeInsertNode.className = "hide"
  cCodePopNode.className = "code"
    e.preventDefault()
    let stackAux = stack
   
    if(stackAux.length == 0 )
        alert("La pila esta vacía. No hay nada que sacar")
    else{
        auxNY = nodeY
        stackAux.pop()
        // localStorage.setItem("Stack", stackAux)
        drawStack(stackAux)
    }

})



saveButton.addEventListener("click", (e) => {
    e.preventDefault();
    localStorage.setItem("Stack", JSON.stringify(stack))
})

loadButton.addEventListener("click", (e) => {
    e.preventDefault();
    if(localStorage.getItem("Stack")){
        stack = JSON.parse(localStorage.getItem("Stack"))
        drawStack(stack)
        saveButton.className="btn"
        createNodeButton.className = "btn"
        popButton.className="btn"
        document.getElementById("stackNodeValue").className="hide"
  newButton.className="hide"
        
    }
})
newButton.addEventListener("click", (e) => {
  e.preventDefault()
  newButton.className="hide"
  loadButton.className="btn"
  popButton.className="btn"
  pushButton.className="hide"
  createButton.className="btn"
  saveButton.className="btn"
  createButton.className="hide"
  document.getElementById("stackNodeValue").className="hide"
  createNodeButton.className="btn"
  popButton.disabled = true
  loadButton.disabled = false

})
createNodeButton.addEventListener("click", (e) => {
  e.preventDefault()
  if(stack.length > 7){
    alert("La pila esta llena, no puedes agregar más nodos")
    return
}
  createNodeButton.disabled = true
  createButton.className = "btn"
  document.getElementById("stackNodeValue").className=""
  canvasContext.clearRect(0, 0, canvasWidth, y+nodeSize*2)

})