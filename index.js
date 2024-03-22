/*---------hosting concept------------*/
var x = 20;

function foo() {
  console.log(x); // undefined
  var x = 10;
  //   let x = 10; // refernceError
}
foo();

console.log("start"); // 1
setTimeout(() => {
  console.log("Timeout"); // 3
}, 0);
console.log("end"); // 2

async function foo() {
  return "Hello world";
}

const result = foo();
console.log(result); // Promise object

console.log([1, 2] == [1, 2]); // false
console.log({} == {}); // false

const user1 = {
  name: "Santosh",
  age: 25,
  address: {
    city: "Noida",
    state: "Uttar Pradesh",
  },
};

const user2 = user1;
user2.name = "Sumit";
user1.address.city = "New Delhi";

console.log(user1);
console.log(user2);

const numbers = [0, 1, 2, 3, 4, 5];

const filterNumber = numbers.filter((i) => i < 3).map((value) => value + 5);

console.log(filterNumber);

const str = "hi i am santosh";

const arr = str.split(" ");
const capitalizedArr = arr.map(
  (word) => word.charAt(0).toUpperCase() + word.slice(1)
);
console.log(capitalizedArr);
