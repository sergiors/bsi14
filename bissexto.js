#!/usr/bin/env node

var readline = require('readline');

var r1 = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

r1.question('Digite um ano:', function(year) {

  if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
    console.log('O ano', year, 'é bissexto');
  } else {
    console.log('O ano', year, 'não é bissexto');
  }
  
  r1.close();
});
