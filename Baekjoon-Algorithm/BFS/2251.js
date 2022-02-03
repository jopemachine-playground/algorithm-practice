const fs = require('fs');
// const [first] = `
// 8 9 10`
  // .trim()
  // .split('\n')
const [first] = fs.readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split('\n')

const capacity = first.split(' ').map(str => Number(str));
const [capacityA, capacityB, capacityC] = capacity;
const sum = capacityC;

const visited = Array.from(Array(201), () => Array(201).fill(false));

const go = () => {
  const result = new Set;

  const que = [];
  que.push({ a: 0, b: 0 });

  while(que.length > 0) {
    const {a, b} = que.shift();
    const c = sum - a - b;
    const buckets = [a, b, c];

    // source 물통
    for (let i = 0; i < 3; ++i) {
      // dest 물통
      for (let j = 0; j < 3; ++j) {
        if (i === j) continue;
        let source = 0;
        // dest에 source의 물의 양을 일단 무지성으로 더한다.
        let dest = buckets[i] + buckets[j];

        // dest의 수용량보다 많이 들어간 경우 덜어낸다.
        if (dest > capacity[j]) {
          source = dest - capacity[j];
          dest = capacity[j];
        }

        // 물통 양 업데이트
        const nextBuckets = [];
        nextBuckets[i] = source;
        nextBuckets[j] = dest;
        nextBuckets[3 - i - j] = sum - source - dest;

        if (!visited[nextBuckets[0]][nextBuckets[1]]) {
          // console.log('----------------------------------------');
          // console.log('i: ', i);
          // console.log('j: ', j);
          // console.log('nextBuckets: ', nextBuckets);

          visited[nextBuckets[0]][nextBuckets[1]] = true;

          que.push({
            a: nextBuckets[0],
            b: nextBuckets[1],
          });

          if (nextBuckets[0] === 0) {
            result.add(nextBuckets[2]);
          }
        }
      }
    }
  }

  return [...result.values()].sort((a, b) => a - b);
};

console.log(go().join(' '));