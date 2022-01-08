import * as fs from "fs";
const input = fs.readFileSync("/dev/stdin").toString().split(" ");
const n1 = parseInt(input[0]);
const n2 = parseInt(input[1]);
const n12 = parseInt(input[2]);
console.log(Math.floor((n1+1)*(n2+1)/(n12+1)-1));
