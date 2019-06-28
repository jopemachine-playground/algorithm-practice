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

int cache[1000001];

void solve_1463() {

	// 캐시를 -1로 전부 초기화
	memset(cache, 0, sizeof(cache));
	cache[2] = 1;
	cache[3] = 1;

	// Prev Conv:: 1 <= N <= 10 ^ 6
	cin >> input;

	for (int i = 4; i <= input; i++) {
		
		if (i % 3 == 0 && i % 2 != 0) {
			cache[i] = min(cache[i - 1], cache[i / 3]) + 1;
		}
		else if (i % 3 != 0 && i % 2 == 0) {
			cache[i] = min(cache[i - 1], cache[i / 2]) + 1;
		}
		else if (i % 3 == 0 && i % 2 == 0) {
			cache[i] = min(min(cache[i / 3], cache[i / 2]), min(cache[i / 2], cache[i - 1])) + 1;
		}
		else {
			cache[i] = cache[i - 1] + 1;
		}
	}

	cout << cache[input];

}