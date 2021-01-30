function solution(people, limit) {
  var answer = 0;

  people.sort((a, b) => a - b);

  let sIdx = 0,
    eIdx = people.length - 1;

  while (sIdx <= eIdx) {
    if (people[sIdx] + people[eIdx] <= limit) {
      ++sIdx;
      --eIdx;
    } else {
      --eIdx;
    }
    ++answer;
  }

  return answer;
}
