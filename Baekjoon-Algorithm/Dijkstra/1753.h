//
// Created by wonma on 2019-07-02.
//

#ifndef SELFMADE_ALGORITHM_1753_H
#define SELFMADE_ALGORITHM_1753_H

#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

// V: ������ ����, K: ������ ����
// (1��V��20,000, 1��E��300,000)
int V, K;
int startVertex;

// First: ����ġ (cost), Second: ���� ID
// Min Heap���� ���� ���� greater�� ���
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int s, int** map, int* costs){

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
        for(int i = 0; i < V; i++){

            if(map[vertexID][i] >= 0){

                int totalCost = map[vertexID][i] + costs[vertexID];

                // �ִܰŸ��� �̹� ������ ��
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
        // �� �� ���� ���� -1�� ǥ��
        memset(map[i], -1, sizeof(int) * V);
    }

    for (int i = 0; i < K; i++){
        int startPoint;
        int destPoint;
        // ( 0 <= cost <= 100,000 ) ����ġ
        int cost;
        cin >> startPoint >> destPoint >> cost;

        // ������� �������� ���� ��찡 ���� �� �ִٸ� ���� ���� ����� ������
        // ��Ŀ� �߰��Ѵ�
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
