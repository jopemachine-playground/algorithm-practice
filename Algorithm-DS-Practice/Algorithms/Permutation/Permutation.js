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

console.log(getPermutations([1, 2, 3, 4]));