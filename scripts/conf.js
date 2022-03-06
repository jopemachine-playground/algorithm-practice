import Conf from 'conf';

const schema = {
	extension: {
		type: 'string',
		default: 'cpp',
	},
	template: {
		type: 'string',
		default: './scripts/template',
	},
	commentTemplate: {
		type: 'string',
		default: './scripts/commentTemplate',
	},
};

const config = new Conf({
	schema,
	projectName: 'baekjoon-solve',
});

const reset = () => {
	config.clear();
};

export {
	config,
	reset,
};
