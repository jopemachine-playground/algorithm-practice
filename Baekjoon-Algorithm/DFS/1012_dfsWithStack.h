#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <stack>
#include <memory.h>

int testNumber;

int fieldRow;
int fieldCol;
int CabbageNum;

int** map;
int** visitedPlace;

// 배추 흰 지렁이의 숫자
int *islandNumber;

using namespace std;

stack<pair<int, int>> dfsStk;

// 스택으로 재귀 없이 풀어봄
void solve_1012() {
	cin >> testNumber;

	for (int i = 0; i < testNumber; i++) {
		islandNumber = new int[testNumber];
		memset(islandNumber, 0, sizeof(int) * testNumber);
	}

	for (int i = 0; i < testNumber; i++) {

		cin >> fieldRow >> fieldCol >> CabbageNum;

		map = new int* [fieldCol];
		visitedPlace = new int* [fieldCol];

		for (int j = 0; j < fieldCol; j++) {
			map[j] = new int[fieldRow];
			visitedPlace[j] = new int[fieldRow];
			memset(map[j], 0, sizeof(int) * fieldRow);
			memset(visitedPlace[j], 0, sizeof(int) * fieldRow);
		}

		for (int j = 0; j < CabbageNum; j++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int j = 0; j< fieldCol; j++) {
			for (int k = 0; k < fieldRow; k++) {
				
				if (map[j][k] == 0) {
					continue;
				}
				bool isIsland = false;

				// 시작점을 푸시해 놓는다
				dfsStk.push(make_pair(j, k));

				while (!dfsStk.empty()) {

					int col = dfsStk.top().first;
					int row = dfsStk.top().second;
					dfsStk.pop();
					
					// 고립된 섬의 케이스
					if ((row + 1 >= fieldRow || map[col][row + 1] == 0) &&
						(col + 1 >= fieldCol || map[col+1][row] == 0) && 
						(row - 1 < 0 || map[col][row - 1] == 0) &&
						(col - 1 < 0 || map[col - 1][row] == 0) &&						
						map[col][row] == 1 && visitedPlace[col][row] != 1) 
					{
						//visitedPlace[col][row] = 1;
						isIsland = true;
					}

					// 오른쪽 이동
					if ((row + 1 < fieldRow && row >= 0) && map[col][row + 1] == 1 && visitedPlace[col][row + 1] != 1) {
						dfsStk.push(make_pair(col, row + 1));
						visitedPlace[col][row] = 1;
						visitedPlace[col][row + 1] = 1;
						isIsland = true;
					}
					// 아래 방향
					if ((col + 1 < fieldCol && col >= 0) && map[col + 1][row] == 1 && visitedPlace[col+1][row] != 1) {
						dfsStk.push(make_pair(col + 1, row));
						visitedPlace[col][row] = 1;
						visitedPlace[col + 1][row] = 1;
						isIsland = true;
					}
					// 왼쪽 방향
					if (row - 1 >= 0 && map[col][row - 1] == 1 && visitedPlace[col][row-1] != 1) {
						dfsStk.push(make_pair(col, row - 1));
						visitedPlace[col][row] = 1;
						visitedPlace[col][row - 1] = 1;
						isIsland = true;
					}
					// 위쪽 방향
					if (col - 1 >= 0 && map[col - 1][row] == 1 && visitedPlace[col-1][row] != 1) {
						dfsStk.push(make_pair(col - 1, row));
						visitedPlace[col][row] = 1;
						visitedPlace[col - 1][row] = 1;
						isIsland = true;
					}

					if (dfsStk.empty() && isIsland == true) {
						islandNumber[i]++;
						break;
					}
				}
			}
		}
	}

	/*
		for (int j = 0; j < fieldCol; j++) {
		for (int k = 0; k < fieldRow; k++) {
			cout << visitedPlace[j][k] << " ";
		}
		cout << "\n";
	}

	*/

	for (int i = 0; i < testNumber; i++) {
		cout << islandNumber[i] << "\n";
	}


}