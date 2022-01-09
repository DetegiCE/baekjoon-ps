const fs = require('fs');
const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map((c: any) => parseInt(c));

const ant: number = input[0];
const eye: number = input[1];

if (ant >= 3 && eye <= 4) 
    console.log('TroyMartian')
if (ant <= 6 && eye >= 2)
    console.log('VladSaturnian')
if (ant <= 2 && eye <= 3)
    console.log('GraemeMercurian')
