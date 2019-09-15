/*
==============================+===============================================================
@ File Name : 1918_inorder2PostOrder.h
@ Author : jopemachine
@ Desc : 
@    ** Fail **
@    후위 표기식
@    계산기 작성에 이용한 알고리즘.
==============================+===============================================================
*/

#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input;
// opeator stack
stack<char> stk;


void solution_1918() {
	char str[1000]; //input
	char output[1000]; // output

	scanf("%s", str);

	stack<char> s;
	int oIdx = 0;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			output[oIdx++] = str[i]; // A~Z
		}
		else {

			if (str[i] == '(') s.push(str[i]);
			else if (str[i] == ')') {
				while (s.top() != '(') {
					output[oIdx++] = s.top();
					s.pop();
				}
				s.pop();
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					output[oIdx++] = s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else {
				while (!s.empty() && s.top() != '(') {
					output[oIdx++] = s.top();
					s.pop();
				}
				s.push(str[i]);

			}
		}
	}

	while (!s.empty()) {
		output[oIdx++] = s.top();
		s.pop();
	}
	output[oIdx] = '\0';

	printf("%s\n", output);

}

void solve_1918() {

	cin >> input;

	for (int i = 0; i < input.size(); i++) {

		if (input.at(i) == '*' || input.at(i) == '/') {

			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				cout << stk.top();
				stk.pop();
			}
			stk.push(input.at(i));
		}

		else if (input.at(i) == '+' || input.at(i) == '-') {

			while (!stk.empty() && stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.push(input.at(i));
		}

		else if (input.at(i) == '(') {
			stk.push('(');
		}

		else if (input.at(i) == ')') {

			while (stk.top() != '(') {

				cout << stk.top();
				stk.pop();

			}
			stk.pop();
		}

		else {
			cout << input.at(i);
		}

	}

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}
