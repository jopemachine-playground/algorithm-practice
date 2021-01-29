function solution(s) {
  return s
    .split(" ")
    .map((word) => {
      if (word[0]) {
        return (
          word[0].toUpperCase() + word.substr(1, word.length - 1).toLowerCase()
        );
      }
      return undefined;
    })
    .join(" ");
}
