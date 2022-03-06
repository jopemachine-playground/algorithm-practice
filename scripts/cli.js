import clipboard from 'clipboardy';
import {
	run,
	addAnswer,
	addTest,
	clearTests,
	commitProblem,
	fetchTests,
	setProblem,
	openProblem,
	createProblem,
} from './api.js';
import {reset} from './conf.js';

const command = process.argv[2];
const problemNumber = process.argv[3];

switch (command) {
	case 'run':
	case 'test':
		const testNumber = process.argv[3] ?? undefined;
		run(testNumber);
		break;
	case 'addTest':
		addTest(clipboard.readSync());
		break;
	case 'addAnswer':
		addAnswer(clipboard.readSync());
		break;
	case 'resetConfig':
		reset();
		break;
	case 'set':
		setProblem(problemNumber);
		break;
	case 'open':
		openProblem(problemNumber);
		break;
	case 'commit':
		commitProblem(problemNumber);
		break;
	case 'fetchTest':
		fetchTests(problemNumber);
		break;
	case 'clear':
		clearTests();
		break;
	case 'createProblem':
		createProblem(problemNumber);
		break;
	default:
		throw new Error('Unknown command');
}
