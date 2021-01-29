function solution(numbers) {
  if (numbers.length === 0) return "";

  const newNumbers = numbers.map((number) => {
    if (number < 10) {
      return {
        number,
        comp: 1111 * number,
      };
    } else if (number >= 10 && number < 100) {
      return {
        number,
        comp: number * 101,
      };
    } else if (number >= 100 && number < 1000) {
      return {
        number,
        comp: number * 10 + number / 100,
      };
    } else
      return {
        number,
        comp: number,
      };
  });

  const nums = newNumbers
    .sort((a, b) => b.comp - a.comp)
    .map((number) => number.number);
  if (nums[0] === 0) return "0";
  else return nums.join("");
}
