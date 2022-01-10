const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 3 10
// 1 1
// 2 2
// 3 3
// 1
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// `.trim().split('\n');

const [N, K] = first.split(' ').map(e => +e);

// Ref: 종만북
// max heap의 구현
class Heap {
  arr = [];

  constructor (arr = []) {
    this.arr = arr;
  }

  push (item) {
    this.arr.push(item);
    let idx = this.arr.length - 1;
    let parentIdx = Math.floor((idx - 1) / 2);

    while (idx > 0 && this.arr[idx] > this.arr[parentIdx]) {
      [this.arr[parentIdx], this.arr[idx]] = [this.arr[idx], this.arr[parentIdx]];
      idx = Math.floor((idx - 1) / 2);
      parentIdx = Math.floor((idx - 1) / 2);
    }
  }

  pop() {
    if (this.arr.length === 1) {
      this.arr = [];
      return;
    }

    this.arr[0] = this.arr.pop();

    let idx = 0;

    while (true) {
      const left = 2 * idx + 1;
      const right = 2 * idx + 2;

      // 리프 도착
      if (left >= this.arr.length) break;

      let next = idx;
      if (this.arr[left] > this.arr[next]) {
        next = left;
      }
      
      if (right < this.arr.length && this.arr[right] > this.arr[next]) {
        next = right;
      }

      // 리프 도착
      if (next === idx) break;
      [this.arr[next], this.arr[idx]] = [this.arr[idx], this.arr[next]];
      idx = next;
    }
  }
}

const jewels = inputs.slice(0, N);
const jewelInfo = [];
const bags = inputs.slice(N).map(e => +e);

for (const jewel of jewels) {
  const [M, V] = jewel.split(' ').map(e => +e);
  jewelInfo.push({
    weight: M,
    value: V,
  });
}

jewelInfo.sort((a, b) => a.weight < b.weight ? -1 : 1);
bags.sort((a, b) => a < b ? -1 : 1);

// pq에 중복된 보석을 넣지 않게 반복문 바깥으로 빼야함에 유의.
let idx = 0;
let answer = 0;

const pq = new Heap();

for (let i = 0; i < K; ++i) {
  // i 번째 가방에 들어갈 수 있는 모든 jewel들을 찾아서 pq에 넣는다.
  while (idx < N && jewelInfo[idx].weight <= bags[i]) {
    pq.push(jewelInfo[idx].value);
    idx++;
  }

  if (pq.arr.length !== 0) {
    answer += pq.arr[0];
    pq.pop();
  }
}

console.log(answer);