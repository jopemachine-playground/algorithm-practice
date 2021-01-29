function solution(clothes) {
  const cases = {};

  clothes.map((clothObj) => {
    const cloth = clothObj[1];

    if (cases[cloth]) ++cases[cloth];
    else cases[cloth] = 1;
  });

  const caseCnts = Object.keys(cases).map((key) => cases[key]);

  return caseCnts.reduce((accum, caseCnt) => accum * (caseCnt + 1), 1) - 1;
}
