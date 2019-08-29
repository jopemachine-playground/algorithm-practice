/*
==============================+===============================================================
@ File Name : 1987_Alphabet.h
@ Author : jopemachine
@ Desc : 
@    알파벳
@    DFS 문제.
@    solve_dfs 내에서 isInArray를 4번씩 호출해 배열에 들어 있는 값인지 검사했다.
==============================+===============================================================
*/
#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <stack>
#include <memory.h>

int width;
int height;

char** map;

char* pastpath_array;
int pastpath_arraysize;

using namespace std;

bool isInArray(char target, int depth) {
	for (int i = 0; i <= depth; i++) {
		if (pastpath_array[i] == target) {
			return true;
		}
	}
	return false;
}

void solve_dfs(int row, int col, int depth) {

	pastpath_array[depth] = map[col][row];

	// ������ �������� dfs
	if ((row + 1 < width && row >= 0) && !isInArray(map[col][row + 1], depth)) {
		solve_dfs(row + 1, col, depth + 1);
	}
	// �Ʒ� �������� dfs
	if ((col + 1 < height && col >= 0) && !isInArray(map[col + 1][row], depth)) {
		solve_dfs(row, col + 1, depth + 1);
	}
	// ���� �������� dfs
	if (row - 1 >= 0 && !isInArray(map[col][row - 1], depth)) {
		solve_dfs(row - 1, col, depth + 1);
	}
	// ���� �������� dfs
	if (col - 1 >= 0 && !isInArray(map[col - 1][row], depth)) {
		solve_dfs(row, col - 1, depth + 1);
	}

}

void solve_1987() {

	cin >> height >> width;

	string* line = new string[height];

	map = new char* [height];
	pastpath_array = new char [height * width];
	memset(pastpath_array, 0, sizeof(char) * height * width);

	pastpath_arraysize = 0;

	for (int i = 0; i < height; i++) {
		map[i] = new char[width];
		memset(map[i], 0, sizeof(char) * width);
	}

	for (int i = 0; i < height; i++) {
		cin >> line[i];

		for (int j = 0; j < line[i].length(); j++) {
			map[i][j] = line[i].at(j);
		}
	}

	/*
		for (int j = 0; j < height; j++) {
		for (int k = 0; k < width; k++) {
			cout << map[j][k] << " ";
		}
		cout << "\n";
	}
	*/

	solve_dfs(0, 0, 0);
	cout << strlen(pastpath_array);
}
