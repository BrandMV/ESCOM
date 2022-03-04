
//Programa #1

function min(a,b){
    if(a<b)
        return a;
    else    
        return b;
}
console.log(min(20,6));

//Programa #2

function palindromo(p){
    let pali="";
    for (let i=p.length;i>=0;i--) 
        pali+=p.charAt(i);
    if (pali==p)
        return true;
    else    
        return false;
}
console.log(palindromo("azuza"));

//programa #3

function ocurrencias(pal, letra){
    let veces=0;
    for(let i=0;i<pal.length;i++){
        if(letra==pal.charAt(i))
            veces++;
    }
    return veces;
}
console.log(ocurrencias("casasa","a"));

//Programa #4

function inversa(num){
    numero=num.toString();
    inver="";
    for(let i=numero.length;i>=0;i--)
         inver+=numero.charAt(i);
    return parseInt(inver);
}
console.log(inversa(12345));

//Programa #5

function factorial(num){
    let res=1;
    for(let i=1; i<=num;i++)
        res*=i;
    return res;
}
console.log(factorial(5));

//Programa #5 b
function factorialR(num){
    if(num==0)
        return 1;   
    else
        return num*factorialR(num-1);
}
console.log(factorialR(6));

//Programa #6
function createBase(num){
    return function(n){
        return num+n;
    }
}
var addsix=createBase(6);
console.log(addsix(10));
console.log(addsix(21));






