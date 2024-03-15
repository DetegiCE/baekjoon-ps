const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n;
let g = [];

rl.question('', (answer) => {
  n = parseInt(answer);
  readGrid(0);
});

function readGrid(row) {
  if (row < n) {
    rl.question('', (line) => {
      g.push(line.split(''));
      readGrid(row + 1);
    });
  } else {
    let t = 0;
    for (let i = n - 1; i >= 0; i--) {
      for (let j = n - 1; j >= 0; j--) {
        if (g[i][j] === '1') {
          t++;
          for (let a = 0; a <= i; a++) {
            for (let b = 0; b <= j; b++) {
              if (g[a][b] === '1') {
                g[a][b] = '0';
              } else {
                g[a][b] = '1';
              }
            }
          }
        }
      }
    }
    console.log(t);
    rl.close();
  }
}
