function solution(A, B) {
  var answer = 0;

  A.sort((a, b) => a - b);
  B.sort((a, b) => b - a);

  A.map((number, index) => {
    answer += number * B[index];
  });

  return answer;
}
