const makeNext = (num) => {
  const str = String(num);
  
  let res = 0;
  for (const ch of str) {
    res += Number(ch)
  }

  return res + num;
};

let pt = 1;
const check = [];

for (let i = 1; i < 100001; ++i) {
  let n = makeNext(i);
  if (n < 10001) {
    check[n] = true;
  }
}

for (let i = 1; i < 10000; ++i) {
  if (!check[i]) console.log(i);
}