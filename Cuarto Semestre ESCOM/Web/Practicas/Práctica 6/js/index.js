let num1, num2, sum, res, fac1, fac2, pot, pot2;

num1 = parseInt(prompt("Ingresa un número"));
num2 = parseInt(prompt("Ingresa un segundo número"));

console.log(num1);
console.log(num2);

const parOImpar = () => {
  let n1, n2;
  n1 = num1;
  n2 = num2;

  if (n1 % 2 === 0) alert("El número " + n1 + " es par");
  else alert("El numero " + n1 + " es impar");

  if (n2 % 2 === 0) alert("El número " + n2 + " es par");
  else alert("El numero " + n2 + " es impar");
};
19;
const suma = () => {
  let n1, n2;
  n1 = num1;
  n2 = num2;
  sum = n1 + n2;
  console.log(sum);
  alert("La suma de los números es: " + n1 + "+" + n2 + "=" + sum);
};

const resta = () => {
  let n1, n2;
  n1 = num1;
  n2 = num2;
  res = n1 - n2;
  console.log(res);
  alert("La resta de los números es: " + n1 + "-" + n2 + "=" + res);
};

const factorial = () => {
  let n = num1;
  let n2 = num2;
  let fac = 1;
  let fac2 = 1;
  for (i = 1; i <= n; i++) fac = fac * i;

  for (i = 1; i <= n2; i++) fac2 = fac2 * i;

  alert(
    "El factorial de " +
      num1 +
      " es " +
      fac +
      " y el de " +
      num2 +
      " es " +
      fac2
  );
};

const potencia = () => {
  let n1, n2;
  n1 = num1;
  n2 = num2;
  pot = Math.pow(n1, n2);
  pot2 = Math.pow(n2, n1);
  alert(
    n1 +
      " elevado a la " +
      n2 +
      " es " +
      pot +
      " y " +
      n2 +
      " elevado a la " +
      n1 +
      " es " +
      pot2
  );
};

const divisible = () => {
  let n1, n2;
  n1 = num1;
  n2 = num2;

  if (n1 % n2 == 0) alert(n1 + " es divisble por " + n2);
  else alert(n1 + " no es divisible por " + n2);

  if (n2 % n1 == 0) alert(n2 + " es divisble por " + n1);
  else alert(n2 + " no es divisible por " + n1);
};
