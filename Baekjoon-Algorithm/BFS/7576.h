/*
==============================+===============================================================
@ File Name : 7576.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_7576_H
#define ALGORITHM_7576_H

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

queue<pair<int, int>> que;

void bfs(int** map, int** dist, int MAX_X, int MAX_Y){

    while(!que.empty()){

        int x = que.front().second;
        int y = que.front().first;

        // Up
        if(y - 1 >= 0    && map[y-1][x] == 0){
            que.push({y-1, x});
            map[y-1][x]  = 1;
            dist[y-1][x] = dist[y][x] + 1;
        }

        // Down
        if(y + 1 < MAX_Y && map[y+1][x] == 0){
            que.push({y+1, x});
            map[y+1][x]  = 1;
            dist[y+1][x] = dist[y][x] + 1;
        }

        // Left
        if(x - 1 >= 0    && map[y][x-1] == 0){
            que.push({y, x-1});
            map[y][x-1]  = 1;
            dist[y][x-1] = dist[y][x] + 1;
        }

        // Right
        if(x + 1 < MAX_X && map[y][x+1] == 0){
            que.push({y, x+1});
            map[y][x+1]  = 1;
            dist[y][x+1] = dist[y][x] + 1;
        }

        que.pop();
    }

}

void solve_7576() {
    // 2 �� M,N �� 1,000
    int    N,   M;
    cin >> N >> M;

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

    bool allTomatoRipes = true;
//    queue<pair<int, int>> inputQue;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if     (map[i][j] == 1){
                // {y, x}
                que.push({i, j});
                dist[i][j] = 1;
            }
            else if(map[i][j] == 0){
                allTomatoRipes = false;
            }
        }
    }

    if(!allTomatoRipes) {

        bfs(map, dist, N, M);

        // if zero does not exist in dist
        // find dist's max value,
        // and return -1

        int maxDist = dist[0][0];
        bool isPossible = true;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {

                if (maxDist < dist[i][j]) {
                    maxDist = dist[i][j];
                }

                if (dist[i][j] == 0 && map[i][j] == 0) {
                    isPossible = false;
                    break;
                }
            }
        }

        if (isPossible) {
            cout << maxDist - 1;
        } else {
            cout << -1;
        }


        for(int i = 0; i < M; i++){
            for(int j  = 0; j < N; j++){
                cout << dist[i][j] << " ";
            }
            cout << "\n";
        }

    }
    else{
        cout << 0;
    }
}

#endif //ALGORITHM_7576_H
