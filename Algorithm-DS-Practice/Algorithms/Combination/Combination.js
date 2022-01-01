const comb = (arr, r, idx = 0, targetIdx = 0, selected = []) => {
  // 다 뽑았을 때
  if (r === 0) {
    selected.forEach((num) => {
      process.stdout.write(num + ' ');
    });

    console.log();
  } else if (targetIdx >= arr.length) {
    return;
  }
  else {
    selected[idx] = arr[targetIdx];
    // arr의 해당 원소 (arr[targetIdx])를 뽑는 경우 => idx를 1 증가시켜 selected에 넣은 정보를 유지하고 다음 인덱스의 숫자를 결정.
    comb(arr, r - 1, idx + 1, targetIdx + 1, selected);
    // arr의 해당 원소 (arr[targetIdx])를 안 뽑는 경우 => idx를 그대로 유지시켜 다른 값으로 교체되게 만듬.
    comb(arr, r, idx, targetIdx + 1, selected);
  }
}

comb([1, 3, 5, 7, 9], 2);