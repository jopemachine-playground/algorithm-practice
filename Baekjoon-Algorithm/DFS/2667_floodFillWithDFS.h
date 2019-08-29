/*
==============================+===============================================================
@ File Name : 2667_floodFillWithDFS.h
@ Author : jopemachine
@ Desc : 
@    단지번호붙이기
@    DFS 문제
@ Issue : 
@    cin에 대해 몰랐던 부분이 있어 코드에서 다소 어렵게 입력을 받았는데, 
@    for (int i = 0; i < N; i++) cin >> graph[i]; 와 같이 써서, 입력을 단순하게 받을 수 있다.
==============================+===============================================================
*/
#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

int map_size;

int** map;
vector<int> village;

int dfs_result;

void solve_dfs(int row, int col) {

	// �� �� ���̰ų� �� ���̶��� �ٷ� ����
	if (map[col][row] == 0) {
		return;
	}
	
	map[col][row] = 0;
	dfs_result++;

	// ������ �������� dfs
	if ((row + 1 < map_size && row >= 0) && map[col][row + 1] == 1) { 
		solve_dfs(row + 1, col);
	}
	// �Ʒ� �������� dfs
	if ((col + 1 < map_size && col >= 0) && map[col + 1][row] == 1) {
		solve_dfs(row, col + 1);
	}
	// ���� �������� dfs
	if (row - 1 >= 0 && map[col][row - 1] == 1) {
		solve_dfs(row - 1 , col);
	}
	// ���� �������� dfs
	if (col - 1 >= 0 && map[col - 1][row] == 1) {
		solve_dfs(row, col - 1);
	}

}
void solve_2667() {

	// Prev Cond:: 5 <= N <= 25
	cin >> map_size;

	string *map_oneline = new string[map_size];

	map = new int*[map_size];

	for (int i = 0; i < map_size; ++i) {
		map[i] = new int[map_size];
		memset(map[i], 0, sizeof(int) * map_size);
	}
	
	for (int i = 0; i < map_size; i++) {
		cin >> map_oneline[i];

		for (int j = 0; j < map_size; j++) {
			map[i][j] = map_oneline[i].at(j) - 48;
		}
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			solve_dfs(j, i);
			if (dfs_result != 0) {
				village.push_back(dfs_result);
				dfs_result = 0;
			}
		}
	}

	sort(village.begin(), village.end());

	cout << village.size() << endl;

	for (int i = 0; i < village.size(); i++) {
		cout << village[i] << endl;
	}

}