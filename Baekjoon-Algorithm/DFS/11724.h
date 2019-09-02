/*
==============================+===============================================================
@ File Name : 11724.h
@ Author : jopemachine
@ Desc : 
@    연결 요소의 갯수
@    DFS를 이용하면 간단히 해결할 수 있다. 고립되어 있는 점들도 연결 요소로 카운팅해야 한다.
@    그 외 무향 그래프라는 것에 주의
==============================+===============================================================
*/

#ifndef ALGORITHM_11724_H
#define ALGORITHM_11724_H

#include <iostream>
#include <memory.h>

using namespace std;

static int graph = 0;

void dfs(int** map, int** visited, int N, int start, int depth){
    if(depth == 1){
        graph++;
    }
    bool isIsolated = true;
    for(int i = 0; i < N; i++){
        if(map[start][i] == 1) {
            isIsolated = false;
            if (visited[start][i] == 0 && visited[i][start] == 0) {
                visited[start][i] = 1;
                visited[i][start] = 1;
                dfs(map, visited, N, i, ++depth);
            }
        }
    }
    if (isIsolated) graph++;
}

void solve_11724(){
    int N, M;
    cin >> N;
    cin >> M;

    int **map = new int*[N];
    int **visited = new int*[N];

    for (int i = 0; i < N; ++i) {
        map[i] = new int[N];
        visited[i] = new int[N];
        memset(map[i], 0, sizeof(int) * N);
        memset(visited[i], 0, sizeof(int)* N);
    }

    int u, v;

    for(int i = 0; i < M; i++){
        cin >> u;
        cin >> v;

        map[u-1][v-1] = 1;
        map[v-1][u-1] = 1;
    }

    for(int i = 0; i < N; i++){
        dfs(map, visited, N, i, 0);
    }

    cout << graph;

}


#endif //ALGORITHM_11724_H
