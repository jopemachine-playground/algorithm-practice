//
// Created by wonma on 2019-07-02.
//

#ifndef SELFMADE_ALGORITHM_4963_NUMBEROFISLAND_H
#define SELFMADE_ALGORITHM_4963_NUMBEROFISLAND_H

using namespace std;

#include <iostream>
#include <queue>
#include <memory.h>

// 0 <= w, h <= 50
int W, H;

// 섬의 갯수를 나타내는 int 값, 벡터
int islandNumber = 0;
vector<int> islandNumbers;
queue<pair<int, int>> que;

bool solve_byBFS(pair<int, int> startVertex, int** map, int** dist){

    bool isIsland = false;

    dist[startVertex.second][startVertex.first] = 1;

    que.push(startVertex);

    while(que.size() > 0){

        int row = que.front().first;
        int col = que.front().second;

        // 오른쪽 방향으로 bfs
        if ((row + 1 < W && row >= 0) && map[col][row + 1] == 1 && dist[col][row + 1] < 0) {
            que.push(make_pair(row + 1, col));
            dist[col][row + 1] = dist[col][row] + 1;
            isIsland = true;
        }
        // 아래 방향으로 bfs
        if ((col + 1 < H && col >= 0) && map[col + 1][row] == 1 && dist[col + 1][row] < 0) {
            que.push(make_pair(row, col + 1));
            dist[col + 1][row] = dist[col][row] + 1;
            isIsland = true;
        }
        // 왼쪽 방향으로 bfs
        if (row - 1 >= 0 && map[col][row - 1] == 1 && dist[col][row - 1] < 0) {
            que.push(make_pair(row - 1, col));
            dist[col][row - 1] = dist[col][row] + 1;
            isIsland = true;
        }
        // 위쪽 방향으로 bfs
        if (col - 1 >= 0 && map[col - 1][row] == 1 && dist[col - 1][row] < 0) {
            que.push(make_pair(row, col - 1));
            dist[col - 1][row] = dist[col][row] + 1;
            isIsland = true;
        }

        // 2시 방향으로 bfs (위쪽 방향이면서 오른쪽 방향)
        if(col - 1 >= 0 && (row + 1 < W && row >= 0) && map[col - 1][row + 1] == 1 && dist[col - 1][row + 1] < 0){
            que.push(make_pair(row + 1, col - 1));
            dist[col - 1][row + 1] = dist[col][row] + 1;
            isIsland = true;
        }

        // 4시 방향으로 bfs (아래쪽 방향이면서 오른쪽 방향)
        if((col + 1 < H && col >= 0) && (row + 1 < W && row >= 0) && map[col + 1][row + 1] == 1 && dist[col + 1][row + 1] < 0){
            que.push(make_pair(row + 1, col + 1));
            dist[col + 1][row + 1] = dist[col][row] + 1;
            isIsland = true;
        }

        // 7시 방향으로 bfs (아래쪽 방향이면서 왼쪽 방향)
        if((col + 1 < H && col >= 0) && row - 1 >= 0 && map[col + 1][row - 1] == 1 && dist[col + 1][row - 1] < 0){
            que.push(make_pair(row - 1, col + 1));
            dist[col + 1][row - 1] = dist[col][row] + 1;
            isIsland = true;
        }

        // 11시 방향으로 bfs (위쪽 방향이면서 왼쪽 방향)
        if(col - 1 >= 0 && row - 1 >= 0 && map[col - 1][row - 1] == 1 && dist[col - 1][row - 1] < 0){
            que.push(make_pair(row - 1, col - 1));
            dist[col - 1][row - 1] = dist[col][row] + 1;
            isIsland = true;
        }

        que.pop();
    }

    return isIsland;
}

void solve_4963(){

    bool end = false;

    while(true){

        // dist를 visitedPlace 대신 사용할 수 있다.
        // 다만 이 문제에서 거리 개념이 필요하진 않음
        int** dist;
        int** map;

        cin >> W >> H;

        if(W == 0 && H == 0){
            break;
        }

        map = new int*[H];
        dist = new int*[H];

        for(int i = 0; i < H; i++){
            map[i] = new int[W];
            dist[i] = new int[W];
            memset(map[i], 0, sizeof(int) * W);
            memset(dist[i], -1, sizeof(int) * W);
        }

        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                cin >> map[i][j];
            }
        }

        // 모든 점에서 각 방향으로 모두 BFS 해 본다.
        // dist를 유지해 갔던 방향으로 가지 않는다.
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                if(solve_byBFS({j, i}, map, dist)){
                    islandNumber++;
                };
            }
        }

        islandNumbers.push_back(islandNumber);
        islandNumber = 0;

        for(int k = 0; k < H; k++){
            memset(dist[k], -1, sizeof(int) * W);
        }

    }

    // 벡터에 push해 놓았던 islandNumber 값들을 모두 pop 해 출력함
    for(int i = 0; i < islandNumbers.size(); i++){
        cout << islandNumbers[i] << "\n";
    }
}
#endif //SELFMADE_ALGORITHM_4963_NUMBEROFISLAND_H
