/*
==============================+===============================================================
@ File Name : 14502.h
@ Author : jopemachine
@ Desc : 
@    조합 문제를 처음 접해 어려웠다.
@    DFS로 가능한 모든 경우 (조합)을 만들고 Brute Force로 각 경우들을 점검하면서 안전 구역의 최댓값이 되는 케이스
@    를 구하고 그 최댓값을 출력해야 한다. 
@ Ref URLs : 
@    
@    https://gorakgarak.tistory.com/523
@    https://yabmoons.tistory.com/99
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

void combination_dfs(pair<int,int> index, int count){

    if(count == (M / 2) + 1){
        return;
    }

}

void bfs(int** map, int** dist){

}

void solve_14502(){

    cin >> N >> M;

    // vector below is container for remembering indexes at 0
    vector<pair<int, int>> empty;

    int** dist;
    int** map;

    map  = new int*[M];
    dist = new int*[M];

    for (int i = 0; i < M; i++) {

        map[i]  = new int[N];
        dist[i] = new int[N];
        memset(map[i] , 0, sizeof(int) * N);
        memset(dist[i], 0, sizeof(int) * N);

    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if(map[i][j] == 0){
                // {y, x}
                empty.push_back({i, j});
            }
        }
    }

    combination_dfs({0, 0}, 0);






}

#endif //ALGORITHM_14502_H
