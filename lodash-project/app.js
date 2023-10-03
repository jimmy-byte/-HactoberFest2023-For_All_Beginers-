const { _ } = require('lodash')
String.similarity = require('similarity-string');



// map method
const numbers = [1, 2, 3, 4, 5];
const cubeNumbers = _.map(numbers, num => num * num * num);
console.log(cubeNumbers);

// filter method 
var players = [
    { 'user': 'Rahul', 'age': 36, 'game': 'football' },
    { 'user': 'Vishal',   'age': 40, 'game': 'cricket' },
    { 'user': 'Ankit',   'age': 42, 'game': 'football' }
  ];
   
  console.log(_.filter(players, function(o) { return  o.game === 'football'; }));
 

//reduce method
const numbers = [1, 2, 3, 4, 5];
const sum = _.reduce(numbers, (accumulator, num) => accumulator + num, 0);
console.log(sum);

//sortBy method
var cricketers = [
    { 'name': 'dohni',   'age': 48 },
    { 'name': 'brately', 'age': 36 },
    { 'name': 'shewag',   'age': 40 },
    { 'name': 'aren', 'age': 34 }
  ];
   
  console.log(_.sortBy(cricketers, [function(o) { return o.name; }]));

   
  console.log(_.sortBy(cricketers, ['name', 'age']));
 
//groupBy method
const students = [
    { name: 'Alice', grade: 'A' },
    { name: 'Bob', grade: 'B' },
    { name: 'Charlie', grade: 'A' },
  ];
  const groupedStudents = _.groupBy(students, 'grade');
  
  console.log(groupedStudents);
 

//cloneDeep method
const originalObject = { a: 1, b: { c: 2 } };
const clonedObject = _.cloneDeep(originalObject);
console.log("cloned object" , clonedObject);
  

//flow method
const add = (a, b) => a + b;
const square = x => x * x;
const incrementAndSquare = _.flow([add, square]);

const result = incrementAndSquare(2, 3); 
console.log("output : -",result);

//flatten and chunk method
const nestedArray = [1, [2, 3], [4, 5]];
const flatArray = _.flatten(nestedArray); 
console.log("flatten array :-", flatArray);
const numbers = [1, 2, 3, 4, 5];
const chunkedArray = _.chunk(numbers, 3);
console.log("Chunked array :-",chunkedArray);

// merge and omit method
const object1 = { firstName: 'Lionel' };
const object2 = { lastName: "Messi" };
const mergedObject = _.merge({}, object1, object2); 
console.log("Merged Object" , mergedObject);

const user = { id: 1, name: 'Rahul', email: 'rahul@gmail.com' };
const output = _.omit(user, 'email'); 
console.log(output);

//function
function fetchData() {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        const data = 'Data from server';
        resolve(data);
      }, 1000);
      console.log("kdsdjksd");
    });
  }
  
  fetchData()
    .then((result) => {
      console.log(result);
    })
    .catch((error) => {
      console.error(error);
    });


// to check similarity between two string in percentage
const str1 = "badDebtWORent";
const str2 = "badDebtRentWO";

let percent = String.similarity(str1, str2);

console.log(percent);
