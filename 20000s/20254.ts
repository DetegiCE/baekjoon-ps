import * as fs from "fs";
const input = fs.readFileSync("/dev/stdin").toString().split(" ");
const ur = parseInt(input[0]);
const tr = parseInt(input[1]);
const uo = parseInt(input[2]);
const to = parseInt(input[3]);
console.log(56*ur + 24*tr + 14*uo + 6*to);
