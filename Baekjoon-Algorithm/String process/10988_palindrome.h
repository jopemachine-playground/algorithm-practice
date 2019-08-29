/*
==============================+===============================================================
@ File Name : 10988_palindrome.h
@ Author : jopemachine
@ Desc : 
@    팰린드롬인지 확인하기
@    반복문으로 간단히 확인할 수 있다.
==============================+===============================================================
*/
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