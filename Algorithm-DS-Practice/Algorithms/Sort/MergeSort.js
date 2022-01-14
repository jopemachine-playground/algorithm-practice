const merge = (leftArr, rightArr) => {
  let i = 0, j = 0;
  const result = [];
  while (i < leftArr.length && j < rightArr.length) {
    // 사실 값이 같은 경우는 둘 중 어디에 들어가도 상관 없음.
    if (leftArr[i] <= rightArr[j]) {
      result.push(leftArr[i]);
      ++i;
    } else {
      result.push(rightArr[j]);
      ++j;
    }
  }

  return [
    ...result,
    ...leftArr.slice(i),
    ...rightArr.slice(j)
  ];
};

const mergeSort = (arr) => {
  const mid = Math.floor(arr.length / 2);
  if (arr.length <= 1) {
    return arr;
  }

  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));

  return merge(left, right);
};

console.log(mergeSort([3, 5, 6, 1, 10, 3, 8, 9, 1]));
