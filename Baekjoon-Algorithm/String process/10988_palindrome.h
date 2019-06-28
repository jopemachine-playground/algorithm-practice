#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void solve_10998() {
	string input;
	cin >> input;
	
	bool isPalindrome = true;

	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) != input.at(input.size()-1-i)) {
			isPalindrome = false;
			break;
		}
	}
	cout << (isPalindrome ? "1\n" : "0\n");
}