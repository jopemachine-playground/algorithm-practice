#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int input;
int targetNumber = 0;

void solve_1065() {

	// Prev Cond:: 1<= N <= 1000
	cin >> input;

	for (int i = 1; i <= input; i++) {
		
		// 차(diff) 가 한 개 이하일 땐 항상 한 수이다.
		if (i < 100) {
			targetNumber++;
			continue;
		}

		int div1 = i % 10;
		int div2 = (i % 100) / 10;
		int div3 = i / 100;

		if (div3 - div2 == div2 - div1) {
			targetNumber++;
		}
	}

	cout << targetNumber;
		
}