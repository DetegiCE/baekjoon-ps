const fs = require('fs');
const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ');

const a: number = parseInt(input[0]);
const b: number = parseInt(input[1]);

if (a == b) console.log(a);
else console.log(a > b ? a : b);
