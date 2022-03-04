//ejercicio 1

let obje={shrimps:5, tots: 12}
function toArray(objeto){
    console.log(Object.entries(objeto));
}
toArray(obje)
toArray({})

//ejercicio 2

function studentNote(n,cal){
    est={nombre: "",topNote:""};
    est.nombre=n;
    if(cal.length==0){
        est.topNote=0;
    }else{
        est.topNote=cal.sort(function(a, b){return b-a});
        est.topNote=cal[0];
    }
    return est

}
console.log(studentNote("Carlos", [6,4,9]));

//ejercicio 3

let arr=["A","B","A","A","A"]

function getFrecuencies(arreglo){
    let res = {};

    for(let i = 0; i< arr.length; i++){ 
        let cant = arreglo[i]; 
        res[cant] = res[cant] ? res[cant]+1 : 1;
    }
    return res
}
console.log(getFrecuencies(arr));


//ejercicio 4

let obj = {
    name:"Benny",
    phone: "3232234234",
    email: "benny@edabit.com"

}

let obj2= {
    name:"Jason",
    phone: "3432434234",
    email: "jason@edabit.com"
}

let obj3= {
    name:"Jason",
    phone: "3432434234",
    email: "jason@edabit.com"
}

let obj4= {
    name:"Jason",
    phone: "3432434234",
    email: "jason@edabit.com"
}

function deepEqual(objeto1, objeto2){
    let k1 = Object.keys(objeto1).sort();
    let k2 = Object.keys(objeto2).sort();
    if (k1.length !== k2.length) {
        return false;
    }
    if (k1.join('') !== k2.join('')) {
        return false;
    }
    for (let i=0; i<k1.length; i++) {
        if ( objeto1[k1[i]]  !== objeto2[k2[i]]) {
            return false;
        }
    }
    return true;
}

console.log(deepEqual(obj,obj2)); 
console.log(deepEqual(obj3,obj4));
