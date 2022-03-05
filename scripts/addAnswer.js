import clipboard from 'clipboardy';
import { addAnswer } from './api.js';

addAnswer(clipboard.readSync());