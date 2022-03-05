import got from "got";
import { load } from "cheerio";
import { addTest, addAnswer, clearTests } from './api.js';
const problemNumber = process.argv[2];

(async () => {
  const res = await got(`https://www.acmicpc.net/problem/${problemNumber}`);
  await clearTests();

  const $ = load(res.body);

  for (let i = 1; ; ++i) {
    const sampleInput = $(`#sample-input-${i}`);
    const sampleOutput = $(`#sample-output-${i}`);
    const sampleInputTxt = sampleInput.text();
    const sampleOutputTxt = sampleOutput.text();

    if (!sampleInputTxt || !sampleOutputTxt) break;

    await addTest(sampleInputTxt);
    await addAnswer(sampleOutputTxt);
  }
}) ();