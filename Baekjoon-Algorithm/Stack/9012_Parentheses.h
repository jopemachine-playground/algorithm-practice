#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int stringNumber;
stack<char> charStack;
string* str;

void solve_9012() {

	ios::sync_with_stdio(false);

	cin >> stringNumber;

	str = new string[stringNumber];

	string result = "";

	for (int i = 0; i < stringNumber; i++) {
		cin >> str[i];
	}

	bool f = false;

	for (int i = 0; i < stringNumber; i++) {

		f = false;
		
		for (int j = 0; j < str[i].size(); j++) {
			// ) 가 빈 스택에 들어오면 무조건 NO
			if (charStack.empty() && str[i].at(j) == ')') {
				result += "NO\n";
				f = true;
				break;
			}
			// 스택이 비어있으면 push한다. 또한 같은 괄호가 들어오면 push한다
			if (charStack.empty() || (charStack.top() == '(' && str[i].at(j) == '(')) {
				charStack.push(str[i].at(j));
			}
			// 위에 해당하지 않는다는 것은, 스택이 차 있고, 괄호가 매칭된다는 것이므로 스택에서 pop한다
			else {
				charStack.pop();
			}
		}

		if (!charStack.empty() && !f) {
			result += "NO\n";
		}
		else if (charStack.empty() && !f){
			result += "YES\n";
		}

		while (!charStack.empty()) charStack.pop();
	}

	cout << result;

}