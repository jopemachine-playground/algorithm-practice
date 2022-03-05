import clipboard from 'clipboardy';
import { addTest } from './api.js';

addTest(clipboard.readSync());