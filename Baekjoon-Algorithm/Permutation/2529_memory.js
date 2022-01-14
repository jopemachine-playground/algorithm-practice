// let fs = require('fs');
// const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// const rawInput = `2
// < >
// `;
// const input = rawInput.trim().split("\n");
// 백준에서 입력을 받는 코드
const input = [];
require("readline")
  .createInterface(process.stdin, process.stdout)
  .on("line", (line) => {
    input.push(line);
  })
  .on("close", () => {
    console.log(sol(input));
    process.exit();
  });

const sol = (input) => {
  const getPermutations = (arr, idx = 0) => {
    let result = [];
    if (idx >= arr.length - 1) {
      return [...result, [...arr]];
    }
  
    for (let i = idx; i < arr.length; ++i) {
      [arr[i], arr[idx]] = [arr[idx], arr[i]];
      result = [...result, ...getPermutations(arr, idx + 1)];
      [arr[i], arr[idx]] = [arr[idx], arr[i]];
    }
  
    return result;
  };
  
  const n = Number(input[0]);
  const inputs = input.slice(1)[0].split(' ');
  
  const minCands = new Int8Array(n + 1).map((_, idx) => idx);
  const maxCands = new Int8Array(n + 1).map((_, idx) => 9 - idx);
  
  const check = (cand) => {
    for (let i = 0; i < inputs.length; ++i) {
      if (inputs[i] === '<' && cand[i] > cand[i + 1]) {
        return false;
      } else if (inputs[i] === '>' && cand[i] < cand[i + 1]) {
        return false;
      }
    }
  
    return true;
  };
  
  let max = -1;
  let min = Number.MAX_SAFE_INTEGER;
  
  getPermutations(Array.from(maxCands)).map((cand) => {
    if (check(cand) && max < Number(cand.join(''))) {
      max = cand.join('');
    }
  });
  
  getPermutations(Array.from(minCands)).map((cand) => {
    if (check(cand) && min > Number(cand.join(''))) {
      min = cand.join('');
    }
  });
  
  console.log(max);
  console.log(min);
};
