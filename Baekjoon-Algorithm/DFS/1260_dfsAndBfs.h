#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

/*
참고
https://felixblog.tistory.com/72 - 이차원 배열의 동적 할당
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

int verticeNumber;
int lineNumber;
int start_vertice;
int** adjacentArray;
int* visitedVertices;

queue<int> bfs_queue;

void solve_dfs(int start_vertice) {

	printf("%d ", start_vertice);

	visitedVertices[start_vertice] = 1;
	
	for (int i = 1; i <= verticeNumber; i++) {
		if (adjacentArray[start_vertice][i] == 1 && visitedVertices[i] == 0) {
			visitedVertices[i] = 1;
			solve_dfs(i);
		}
	}
}

void solve_bfs(int start_vertice) {

	if (visitedVertices[start_vertice] == 0) {
		bfs_queue.push(start_vertice);
	}

	visitedVertices[start_vertice] = 1;

	if (bfs_queue.size() <= 0) {
		return;
	}

	int current_vectice = bfs_queue.front();

	printf("%d ", current_vectice);

	bfs_queue.pop();

	for (int i = 1; i <= verticeNumber; i++) {

		if (adjacentArray[current_vectice][i] == 1 && visitedVertices[i] == 0) {
			bfs_queue.push(i);
			visitedVertices[i] = 1;
		}
	}

	solve_bfs(current_vectice);
}


void solve_1260() {

	// Prev Cond:: 1<= verticeNumber <=1000
	// Prev Cond:: 1<= lineNumber <=10000

	scanf("%d %d %d", &verticeNumber, &lineNumber, &start_vertice);

	adjacentArray = new int* [verticeNumber + 1];
	visitedVertices = new int [verticeNumber + 1];
	memset(visitedVertices, 0, sizeof(int) * (verticeNumber + 1));

	for (int i = 1; i < verticeNumber + 1; ++i) {
		adjacentArray[i] = new int[verticeNumber + 1];
		memset(adjacentArray[i], 0, sizeof(int) * (verticeNumber + 1));
	}

	int s, d;

	for (int i = 1; i <= lineNumber; i++) {
		scanf("%d %d", &s, &d);
		adjacentArray[s][d] = 1;
		adjacentArray[d][s] = 1;
	}

	/*
		for (int i = 1; i < verticeNumber + 1; i++) {
		for (int j = 1; j < verticeNumber + 1; j++) {
			printf("%d ", adjacentArray[i][j]);
		}
		printf("\n");
		}
	*/

	// # DFS
	solve_dfs(start_vertice);
	printf("\n");
	memset(visitedVertices, 0, sizeof(int) * (verticeNumber + 1));

	// # BFS
	solve_bfs(start_vertice);


}

