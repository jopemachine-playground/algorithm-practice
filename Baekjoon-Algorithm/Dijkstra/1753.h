/*
==============================+===============================================================
@ File Name : 1753.h
@ Author : jopemachine
@ Desc : 
@    최단경로
@    풀다 계속 메모리 초과가 나서 애를 먹었음. 검색해보니 문제에서 요구하는 입력이 커서
@    그래프를 배열 형태로 표현하면 허용 메모리를 초과한다고 함. 
@    그래서 그래프를 list 형태(vector) 로 바꿔 표현한 후 풀었다. 
@    그 외 배열을 delete로 제거하려 하니 백준 컴파일러에서 런타임 에러가 났었다.
@    배열은 반드시 delete[]로 제거할 것.
==============================+===============================================================
*/

#ifndef SELFMADE_ALGORITHM_1753_H
#define SELFMADE_ALGORITHM_1753_H

#include <iostream>
#include <memory.h>
#include <queue>
#include <list>
using namespace std;

int V, K;
int startVertex;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int startPoint, vector<pair<int, int>>* linkedListArray, int* costs){

    pQue.push({0, startPoint});

    while(pQue.size() > 0){

        int cost     = pQue.top().first;
        int vertexID = pQue.top().second;

        pQue.pop();

        if(costs[vertexID] != -1){
            continue;
        }

        costs[vertexID] = cost;

        auto iter = linkedListArray[vertexID].begin();

        for(int i = 0; i < linkedListArray[vertexID].size(); i++, iter++){

            int totalCost = iter->first + cost;

            if(costs[iter->second] != -1){
                continue;
            }

            pQue.push({totalCost, iter->second});
        }

    }
}

void solve_1753(){
    cin >> V >> K;
    cin >> startVertex;

    int *costs = new int[V];

    for(int i = 0; i < V; i++){
        costs[i] = -1;
    }

    auto linkedListArray = new vector<pair<int, int>>[V];

    for (int i = 0; i < K; i++){
        int startPoint;
        int destPoint;
        // ( 0 <= cost <= 100,000 )
        int cost;
        cin >> startPoint >> destPoint >> cost;

        linkedListArray[startPoint - 1].push_back({cost, destPoint  - 1});
    }

    solve_Dijkstra(startVertex - 1, linkedListArray, costs);

    for (int i = 0; i < V; i++){
        if(costs[i] == -1){
            cout << "INF" << "\n";
            continue;
        }
        cout << costs[i] << "\n";
    }

    delete[] linkedListArray;
}

#endif //SELFMADE_ALGORITHM_1753_H
