
//Programa #1

console.log("Primer programa");
for(let i=0; i<7;i++){
    let a="";
    for(let k=0; k<=i;k++)
    {
        a=a+"*";
    }
  console.log(a);;
    
}

//Programa 2


console.log("Segundo programa");

for(let i=1; i<=100; i++){
    if(i%3==0)
    {
        console.log("Fizz");
        
    }else if(i%5==0 && i%3!=0){
        console.log("Buzz");
        
    }else{
        console.log(i);
    }
    
}

//Programa 2 a

console.log("Segundo programa a");

for(let i=1; i<=100; i++){
    if(i%3==0 && i%5==0){
        console.log("FizzBuzz");
    }else if(i%3==0)
    {
        console.log("Fizz");
        
    }else if(i%5==0 && i%3!=0){
        console.log("Buzz");
        
    }else {
        console.log(i);
    }
        
    
}


//Programa 3 

console.log("Tercer programa");

let cuadro="";

for(let i=0;i<8;i++){
    for(let j=0;j<8;j++){
        if((i+j)%2==0){
            cuadro=cuadro+" ";
        }else{
            cuadro=cuadro+"#";
        }
    }
    cuadro=cuadro+"\n"
}
console.log(cuadro);

/*
//programa 3 b
console.log("Tercer programa b");
let table="";
let ancho=prompt("Ingresa un ancho para el tablero: ");
let altura=prompt("Ingresa una altura para el tablero: ");

for(let i=0;i<altura;i++){
    for(let j=0;j<ancho;j++){
        if((i+j)%2==0){
            table=table+" ";
        }else{
            table=table+"#";
        }
    }
    table=table+"\n"
}
console.log(table);
*/
