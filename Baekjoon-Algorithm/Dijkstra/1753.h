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

// V: ������ ����, K: ������ ����
// (1��V��20,000, 1��E��300,000)
int V, K;
int startVertex;

// First: ����ġ (cost), Second: ���� ID
// Min Heap���� ���� ���� greater�� ���
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int s, list<pair<int, int>> linkedListArray[], int* costs){

    pQue.push({0, s});

    while(pQue.size() > 0){

        int vertexID = pQue.top().second;
        int cost = pQue.top().first;

        pQue.pop();

        // �ִܰŸ��� �̹� ������ ��
        if(costs[vertexID] != -1){
            continue;
        }

        costs[vertexID] = cost;

        // ���� ������ �˻�

        int i = 0;

        for(auto iter = linkedListArray[vertexID].begin(); iter != linkedListArray->end(); iter++, i++){

            if(i >= V) break;

            int totalCost = iter->first + costs[vertexID];

            // �ִܰŸ��� �̹� ������ ��
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
        // ( 0 <= cost <= 100,000 ) ����ġ
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
