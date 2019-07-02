//
// Created by wonma on 2019-07-02.
//

#ifndef SELFMADE_ALGORITHM_1916_H
#define SELFMADE_ALGORITHM_1916_H

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

// N(1 ≤ N ≤ 1,000) 정점의 갯수
// M(1 ≤ M ≤ 100,000) 간선의 갯수
int N, M;

int startingPoint;
int destinationPoint;
// 각 정점 사이의 이동 비용 (cost)
int **map;
// 시작점에서 각 정점으로 가는 최소 비용
int *costs;

// First: 가중치 (cost), Second: 정점 ID
// Min Heap으로 쓰기 위해 greater를 사용
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int s){

    pQue.push({0, s});

    while(pQue.size() > 0){

        int cost = pQue.top().first;
        int vertexID = pQue.top().second;

        pQue.pop();

        // 최단거리가 이미 정해진 곳
        if(costs[vertexID] != -1){
            continue;
        }

        costs[vertexID] = cost;

        // 인접 점들을 검사
        for(int i = 0; i < N; i++){
            if(map[vertexID][i] >= 0){

                int totalCost = map[vertexID][i] + costs[vertexID];

                // 최단거리가 이미 정해진 곳
                if(costs[i] != -1){
                    continue;
                }

                pQue.push({totalCost, i});
            }
        }
    }

}

void solve_1916(){

    cin >> N;
    cin >> M;
    costs = new int[N];

    for(int i = 0; i < N; i++){
        costs[i] = -1;
    }

    map = new int*[N];

    for(int i = 0; i < N; i++){
        map[i] = new int[N];
        // 갈 수 없는 곳은 -1로 표시
        memset(map[i], -1, sizeof(int) * N);
    }

    for (int i = 0; i < M; i++){
        int startPoint;
        int destPoint;
        // ( 0 <= cost <= 100,000 ) 가중치
        int cost;
        cin >> startPoint >> destPoint >> cost;

        // 출발지와 목적지가 같은 버스가 여러 대 있다면 가장 적은 비용의 버스만
        // 행렬에 추가한다
        if(map[startPoint - 1][destPoint - 1] != -1){
            if(cost < map[startPoint - 1][destPoint - 1]){
                map[startPoint - 1][destPoint - 1] = cost;
            }
            else{
                continue;
            }
        }
        else{
            map[startPoint - 1][destPoint - 1] = cost;
        }

    }

    for(int i = 0; i < N; i++){
        map[i][i] = 0;
    }

/*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
*/

    cin >> startingPoint >> destinationPoint;

    solve_Dijkstra(startingPoint - 1);

    cout << costs[destinationPoint - 1];

}
#endif //SELFMADE_ALGORITHM_1916_H
