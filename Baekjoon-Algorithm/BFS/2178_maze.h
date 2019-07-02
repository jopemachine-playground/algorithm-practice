//
// Created by wonma on 2019-07-01.
//

#ifndef SELFMADE_ALGORITHM_2178_MAZE_H
#define SELFMADE_ALGORITHM_2178_MAZE_H

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

// �̷� ������, �Ÿ��� ��� ������ ��� �ݵ�� BFS�� Ǯ��� ����, DFS�δ� Ǯ �� ����

// ���� ����
// N, M(2 �� N, M �� 100)

int N, M;

int **map;
// dist�� visitedPlace�ε� Ȱ���� �� �ִ�.
int **dist;

queue<pair<int, int>> path;

void bfs(int _row, int _col) {

    path.push(make_pair(_row, _col));

    dist[_col][_row] = 1;

    while (path.size() > 0) {

        int row = path.front().first;
        int col = path.front().second;

        // ������ �������� bfs
        if ((row + 1 < M && row >= 0) && map[col][row + 1] == 1 && dist[col][row + 1] < 0) {
            path.push(make_pair(row + 1, col));
            dist[col][row + 1] = dist[col][row] + 1;
        }
        // �Ʒ� �������� bfs
        if ((col + 1 < N && col >= 0) && map[col + 1][row] == 1 && dist[col + 1][row] < 0) {
            path.push(make_pair(row, col + 1));
            dist[col + 1][row] = dist[col][row] + 1;
        }
        // ���� �������� bfs
        if (row - 1 >= 0 && map[col][row - 1] == 1 && dist[col][row - 1] < 0) {
            path.push(make_pair(row - 1, col));
            dist[col][row - 1] = dist[col][row] + 1;
        }
        // ���� �������� bfs
        if (col - 1 >= 0 && map[col - 1][row] == 1 && dist[col - 1][row] < 0) {
            path.push(make_pair(row, col - 1));
            dist[col - 1][row] = dist[col][row] + 1;
        }

        path.pop();

    }
}

void solve_2178() {

    cin >> N >> M;

    string *map_oneline = new string[N];
    map = new int *[N];
    dist = new int *[N];

    for (int i = 0; i < N; ++i) {
        map[i] = new int[M];
        dist[i] = new int[M];
        memset(map[i], 0, sizeof(int) * M);
        memset(dist[i], -1, sizeof(int) * M);
    }

    for (int i = 0; i < N; i++) {
        cin >> map_oneline[i];
        for (int j = 0; j < M; j++) {
            map[i][j] = map_oneline[i].at(j) - 48;
        }
    }

    bfs(0, 0);

    /*
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
      }
    */
    cout << dist[N-1][M-1];
}


#endif //SELFMADE_ALGORITHM_2178_MAZE_H
