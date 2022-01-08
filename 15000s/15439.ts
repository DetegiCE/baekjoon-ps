const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (answer: BigInt) => {
    const inp = Number(answer);
    console.log(inp * (inp-1));
});
