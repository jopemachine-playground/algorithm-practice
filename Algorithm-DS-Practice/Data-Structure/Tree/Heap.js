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

const pq = new Heap();

pq.push(8);
pq.push(7);
pq.push(6);
pq.push(6);
pq.push(6);
pq.push(9);
pq.push(1);
pq.push(5);

pq.pop();
pq.pop();
pq.pop();
pq.pop();
pq.push(5);
pq.push(1);
pq.push(3);
pq.push(3);
pq.pop();
pq.pop();
pq.pop();

console.log(pq.arr);