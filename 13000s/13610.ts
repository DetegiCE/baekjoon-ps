const fs = require('fs');
const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ');

const a: number = parseInt(input[0]);
const b: number = parseInt(input[1]);

console.log(Math.floor(b / (b - a) - 0.1) + 1);
