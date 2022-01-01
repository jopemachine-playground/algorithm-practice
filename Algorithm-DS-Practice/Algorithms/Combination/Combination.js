// nCr => n (arr.length) 개에서 r개를 골라 모든 조합 순서쌍 배열로 만들어 리턴
const getCombination = (arr, r, selectedIdx = 0, arrIdx = 0, selected = []) => {
  let result = [];
  // 다 뽑았을 때
  if (r === 0) {
    result.push([...selected]);
  } else if (arrIdx < arr.length) {
    selected[selectedIdx] = arr[arrIdx];
    // arr의 해당 원소 (arr[arrIdx])를 뽑는 경우 => selectedIdx 1 증가시켜 selected에 넣은 정보를 유지하고 다음 인덱스의 숫자를 결정.
    result = [...result, ...getCombination(arr, r - 1, selectedIdx + 1, arrIdx + 1, selected)];
    // arr의 해당 원소 (arr[arrIdx])를 안 뽑는 경우 => selectedIdx 그대로 유지시켜 다른 값으로 교체되게 만듬.
    result = [...result, ...getCombination(arr, r, selectedIdx, arrIdx + 1, selected)];
  }

  return result;
}

// 1,2
// 1,3
// 1,4
// 2,3
// 2,4
// 3,4
console.log(getCombination([1, 2, 3, 4], 2).join('\n'));

// 1,3
// 1,5
// 1,7
// 1,9
// 3,5
// 3,7
// 3,9
// 5,7
// 5,9
// 7,9
console.log(getCombination([1, 3, 5, 7, 9], 2).join('\n'));
