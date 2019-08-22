/*
############################################################################
############################################################################
############################################################################
############################### Fail #######################################
############################################################################
############################################################################
############################################################################
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

// 아래 코드는 https://donggod.tistory.com/45 에서 가져왔다
// 아래 코드를 보고 내 코드를 고쳐 작동하게 만들었다.
// 사실 핵심 아이디어는 같았는데 (다른 책을 참고해서 짰기 때문에), 
// 내 경우엔 괄호가 있으면 잘 작동하는데, 괄호가 없을 때 버그가 생겨,
// 괄호를 포함하는 문자열을 새로 만들려고 삽질했다

void solution_1918() {
	char str[1000]; //input
	char output[1000]; // output

	scanf("%s", str);

	stack<char> s; // +-*/(를 저장할 스택
	int oIdx = 0; // 출력 문자열의 인덱스

	// str의 문자열을 끝까지
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			output[oIdx++] = str[i]; // A~Z는 출력문자열에 추가
		}
		else {
			//그게아니면 전부 기호이므로
			//아래처럼 처리

			if (str[i] == '(') s.push(str[i]); // '('문자는 무조건 스택에 추가
			else if (str[i] == ')') { // ')'문자는 '('문자를 만날 때까지 pop
				while (s.top() != '(') {
					output[oIdx++] = s.top();
					s.pop();
				}
				s.pop();
			}
			else if (str[i] == '*' || str[i] == '/') {
				//우선순위가 나보다 높거나 같은것을 pop
				//( '/','*'보다 우선순위가 높은것은 없음)
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					output[oIdx++] = s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else { // '+', '-' 인 경우
				while (!s.empty() && s.top() != '(') {
					//우선순위가 나보다 높거나 같은것을 pop
					//('+', '-'보다는 전부 우선순위가 높으므로 '('나 스택이 빌 때까지 pop)
					output[oIdx++] = s.top();
					s.pop();
				}
				s.push(str[i]);

			}
		}
	}

	//스택에 남아있는 것을 전부 pop
	while (!s.empty()) {
		output[oIdx++] = s.top();
		s.pop();
	}
	output[oIdx] = '\0';

	printf("%s\n", output);

}


/*
######################################
######################################
######################################
################ Fail ################
######################################
######################################
######################################
*/

void solve_1918() {

	cin >> input;

	for (int i = 0; i < input.size(); i++) {

		// 우선순위 1
		if (input.at(i) == '*' || input.at(i) == '/') {

			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				cout << stk.top();
				stk.pop();
			}
			stk.push(input.at(i));
		}

		// 우선순위 2
		else if (input.at(i) == '+' || input.at(i) == '-') {

			while (!stk.empty() && stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.push(input.at(i));
		}

		// 우선순위 3
		else if (input.at(i) == '(') {
			stk.push('(');
		}

		// 우선순위 4
		else if (input.at(i) == ')') {

			while (stk.top() != '(') {

				cout << stk.top();
				stk.pop();

			}
			stk.pop();
		}


		// 알파벳
		else {
			cout << input.at(i);
		}

	}

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}
