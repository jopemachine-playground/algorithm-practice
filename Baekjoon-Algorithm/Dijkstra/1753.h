//
// Created by wonma on 2019-07-02.
//

#ifndef SELFMADE_ALGORITHM_1753_H
#define SELFMADE_ALGORITHM_1753_H

#include <iostream>
#include <memory.h>
#include <queue>
#include <list>
using namespace std;

// V: 정점의 갯수, K: 간선의 갯수
// (1≤V≤20,000, 1≤E≤300,000)
int V, K;
int startVertex;

// First: 가중치 (cost), Second: 정점 ID
// Min Heap으로 쓰기 위해 greater를 사용
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int s, list<pair<int, int>> linkedListArray[], int* costs){

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

        int i = 0;

        for(auto iter = linkedListArray[vertexID].begin(); iter != linkedListArray->end(); iter++, i++){

            if(i >= V) break;

            int totalCost = iter->first + costs[vertexID];

            // 최단거리가 이미 정해진 곳
            if(costs[i] != -1){
                continue;
            }

            pQue.push({totalCost, i});

        }
    }
}

void solve_1753(){
    cin >> V >> K;
    cin >> startVertex;

    int *costs;

    costs = new int[V];
    for(int i = 0; i < V; i++){
        costs[i] = -1;
    }

    auto linkedListArray = new std::list<pair<int, int>>[V];

    for (int i = 0; i < K; i++){
        int startPoint;
        int destPoint;
        // ( 0 <= cost <= 100,000 ) 가중치
        int cost;
        cin >> startPoint >> destPoint >> cost;

        linkedListArray[startPoint - 1].push_back({cost, destPoint - 1});
    }

    solve_Dijkstra(startVertex - 1, linkedListArray, costs);

    for (int i = 0; i < V; i++){
        if(costs[i] == -1){
            cout << "INF" << "\n";
            continue;
        }
        cout << costs[i] << "\n";
    }
}

#endif //SELFMADE_ALGORITHM_1753_H
