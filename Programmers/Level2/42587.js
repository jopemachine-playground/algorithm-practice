function solution(priorities, location) {
  var answer = 0;

  const queue = [];

  priorities.map((priority, index) => {
    queue.push({
      index,
      priority,
    });
  });

  priorities.sort((a, b) => a - b);

  while (queue.length !== 0) {
    const top = queue[0];

    if (top.priority >= priorities[priorities.length - 1]) {
      if (top.index === location) {
        return ++answer;
      } else {
        ++answer;
        priorities.pop();
        queue.shift();
      }
    } else {
      queue.push(top);
      queue.shift();
    }
  }

  return answer;
}
