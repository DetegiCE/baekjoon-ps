const fs = require('fs');
const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ')
  .map((c: any) => parseInt(c));

const a: number = input[0];
const b: number = input[1];
const c: number = input[2];

if (a == b && b == c) 
    console.log(2);
else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
    console.log(1);
else console.log(0);
