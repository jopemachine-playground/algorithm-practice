//
// Created by wonma on 2019-07-02.
//

#ifndef SELFMADE_ALGORITHM_1753_H
#define SELFMADE_ALGORITHM_1753_H

#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

// V: 정점의 갯수, K: 간선의 갯수
// (1≤V≤20,000, 1≤E≤300,000)
int V, K;
int startVertex;

// First: 가중치 (cost), Second: 정점 ID
// Min Heap으로 쓰기 위해 greater를 사용
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int s, int** map, int* costs){

    pQue.push({0, s});

    while(pQue.size() > 0){

        int vertexID = pQue.top().second;
        int cost = pQue.top().first;

        pQue.pop();

        // 최단거리가 이미 정해진 곳
        if(costs[vertexID] != -1){
            continue;
        }

        costs[vertexID] = cost;

        // 인접 점들을 검사
        for(int i = 0; i < V; i++){

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

void solve_1753(){
    cin >> V >> K;
    cin >> startVertex;

    int **map;
    int *costs;

    costs = new int[V];
    for(int i = 0; i < V; i++){
        costs[i] = -1;
    }

    map = new int*[V];

    for(int i = 0; i < V; i++){
        map[i] = new int[V];
        // 갈 수 없는 곳은 -1로 표시
        memset(map[i], -1, sizeof(int) * V);
    }

    for (int i = 0; i < K; i++){
        int startPoint;
        int destPoint;
        // ( 0 <= cost <= 100,000 ) 가중치
        int cost;
        cin >> startPoint >> destPoint >> cost;

        // 출발지와 목적지가 같은 경우가 여러 개 있다면 가장 적은 비용의 간선만
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

    solve_Dijkstra(startVertex - 1, map, costs);

    for (int i = 0; i < V; i++){
        if(costs[i] == -1){
            cout << "INF" << "\n";
            continue;
        }
        cout << costs[i] << "\n";
    }
}

#endif //SELFMADE_ALGORITHM_1753_H
