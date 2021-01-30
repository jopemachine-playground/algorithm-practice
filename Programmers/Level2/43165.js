let answer = 0;

function dfs({ target, currentValue, idx, numbers }) {
  if (idx === numbers.length - 1) {
    if ((currentValue + numbers[idx] === target) || (currentValue - numbers[idx] === target)) {
      ++answer;
    }
    return;
  }

  dfs({
    target,
    currentValue: currentValue + numbers[idx],
    idx: idx + 1,
    numbers
  });
  dfs({
    target,
    currentValue: currentValue - numbers[idx],
    idx: idx + 1,
    numbers
  });
}

function solution(numbers, target) {
  let props = {};

  props.target = target;
  props.currentValue = 0;
  props.idx = 0;
  props.numbers = numbers;
  props.answer = 0;

  dfs(props);

  return answer;
}
