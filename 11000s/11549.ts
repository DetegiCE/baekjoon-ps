const fs = require('fs');
const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const a: number = input[0];
const b: number[] = input[1].split(' ');
let count: number = 0;

b.forEach((n: number) => {
    if (n == a) {
        count++;
    }
})
console.log(count);
