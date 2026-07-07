function main() {
    const array = ["Sarthak" , "Sagar" , "Sambhav" , "Sneha" , "Sagun"]

    array.forEach(arr => {
      console.log(arr);
      
    })

    console.log("\n-----------------\n");
    
}
main()

function add(a , b) {
  return a + b;
}

function subtract(a , b) {
  return a - b;
}

function product(a , b ) {
  return a * b;
}

function division(a , b) {
  if(b === 0) 
    return "Error : Division by zero"
  return a / b;
}

function squareroot(n) {
  return Math.sqrt(n);
}

function power(base ,  number) {
  return Math.pow(base , number)
}

function randomInRange(min , max) {
  return Math.floor(Math.random() * (max - min + 1) + min)
}

function getCurrentDate() {
  const now = new Date();
  const hour  = String(now.getHours()).padStart(2, "0")
  const minutes  = String(now.getMinutes()).padStart(2 , "0")
  const second = String(now.getSeconds()).padStart(2, "0")
  return `${hour} : ${minutes} : ${second} `
}

function getDayName() {
  const days = ["Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" ,  "Saturday"]
  return days[new Date().getDay()]
}

const a = 10 , b = 2;

console.log(`The value are : ${a} , ${b}`);

console.log("Add : " , add(a, b));
console.log("Sub : " , subtract(a, b));
console.log("Product : " , product(a, b));
console.log("Divide : " , division(a, b));
console.log("Square Root : " , squareroot(a, b));
console.log("Power : " , power(a, b));
console.log("Random number : " , randomInRange(a, b));
console.log("Current Date : " , getCurrentDate());
console.log("Current Day : " , getDayName());





 

