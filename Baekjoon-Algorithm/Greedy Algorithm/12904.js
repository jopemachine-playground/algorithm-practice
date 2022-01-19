const fs      = require('fs');
let [S, T]    = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// let [S, T]    = `
// BAAB
// BAABA
// `.trim().split("\n");

while (S.length <= T.length && S !== T) {
  if (T.endsWith('A')) {
    // A 제외
    T = T.substring(0, T.length - 1);
  }
  else {
    // B 제외하고 뒤집기
    T = T.substring(0, T.length - 1).split('').reverse().join('');
  }
}

console.log(S === T ? 1 : 0);