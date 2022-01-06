/*
==============================+===============================================================
@ File Name : 14502.h
@ Author : jopemachine
@ Desc : 
@    연구소
@    조합 문제를 처음 접해 어려웠다.
@    BFS로 가능한 모든 경우 (조합)을 만들고 Brute Force로 각 경우들을 점검하면서 안전 구역의 최댓값이 되는 케이스
@    를 구하고 그 최댓값을 출력해야 한다. 
@    이 문제에선 N, M 범위가 굉장히 작기 때문에 (8 이하) 이 방법으로 풀 수 있지만, 입력 범위가 커지면 다른 방법을 찾아야 할 것 같다
@ Ref URLs : 
@    https://gorakgarak.tistory.com/523
@    https://yabmoons.tistory.com/99
@    https://twpower.github.io/90-combination-by-using-next_permutation
@    https://jeonggyun.tistory.com/175
==============================+===============================================================
*/
#ifndef ALGORITHM_14502_H
#define ALGORITHM_14502_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int    N,   M;

void arrayCopy(int** sour, int** dest, int row, int col){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            dest[i][j] = sour[i][j];
        }
    }
}

int zeroCheck(int** map){

    int R = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0) R++;
        }
    }
    return R;
}

void bfs(pair<int, int> startVertex, int** map, int** dist){

    queue<pair<int, int>> que;

    que.push(startVertex);

    while(!que.empty()){

        int row = que.front().first;
        int col = que.front().second;


        if ((row + 1 < N && row >= 0) && map[row + 1][col] == 0 && dist[row + 1][col] < 0) {
            que.push(make_pair(row + 1, col));
            map [row + 1][col] = 2;
            dist[row + 1][col] = dist[row][col] + 1;
        }

        if ((col + 1 < M && col >= 0) && map[row][col + 1]== 0 && dist[row][col + 1] < 0) {
            que.push(make_pair(row, col + 1));
            map [row][col + 1] = 2;
            dist[row][col + 1] = dist[row][col] + 1;
        }

        if (row - 1 >= 0 && map[row - 1][col] == 0 && dist[row - 1][col] < 0) {
            que.push(make_pair(row - 1, col));
            map [row - 1][col] = 2;
            dist[row - 1][col] = dist[row][col] + 1;
        }

        if (col - 1 >= 0 && map[row][col - 1] == 0 && dist[row][col - 1] < 0) {
            que.push(make_pair(row, col - 1));
            map [row][col - 1] = 2;
            dist[row][col - 1] = dist[row][col] + 1;
        }

        que.pop();
    }

}

void solve_14502(){

    cin >> N >> M;

    // container for remembering indexes at 0
    vector<pair<int, int>> allZero;
    // container for remembering indexes at 2
    vector<pair<int, int>> allTwo;

    int** map       = new int*[N];
    int** dist      = new int*[N];
    int** map_temp  = new int*[N];

    for (int i = 0; i < N; i++) {
        map[i]      = new int[M];
        dist[i]     = new int[M];
        map_temp[i] = new int[M];

        memset(map[i] ,     0, sizeof(int) * M);
        memset(map_temp[i], 0, sizeof(int) * M);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if(map[i][j] == 0){
                // {y, x}
                allZero.push_back({i, j});

            }
            else if(map[i][j] == 2){
                allTwo.push_back({i, j});
            }
        }
    }

    vector<int> secureSpaces;
    // Combination
    for(int i = 0; i < allZero.size(); i++){
        for(int j = i + 1; j < allZero.size(); j++){
            for(int k = j + 1; k < allZero.size(); k++){

                arrayCopy(map, map_temp, M, N);

                map_temp[allZero[i].first][allZero[i].second] = 1;
                map_temp[allZero[j].first][allZero[j].second] = 1;
                map_temp[allZero[k].first][allZero[k].second] = 1;

                for(auto& pt : allTwo){
                    bfs(pt, map_temp, dist);
                }

                secureSpaces.push_back(zeroCheck(map_temp));

                for(int l = 0; l < N; l++){
                    for(int m = 0; m < M; m++){
                        dist[l][m] = -1;
                    }
                }
            }
        }
    }

    cout << *max_element(secureSpaces.begin(), secureSpaces.end());

}

#endif //ALGORITHM_14502_H
