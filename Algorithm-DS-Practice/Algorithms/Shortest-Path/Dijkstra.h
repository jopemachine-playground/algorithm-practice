#ifndef SELFMADE_ALGORITHM_DIJKSTRA_H
#define SELFMADE_ALGORITHM_DIJKSTRA_H

#include <queue>
#include "../../Data-Structure/Graph/GraphByMatrix.h"

using namespace std;

// 우선순위 큐를 이용한 다익스트라 알고리즘 구현
// https://jason9319.tistory.com/307 을 보면서 따라 구현했다

vector<int> Dijkstra(GraphByMatrix<int>* graph, int startVertex){

    // 리턴할 최소비용 코스트 vector
    vector<int> costs(graph->row());

    // 다익스트라 알고리즘에서 가중치가 음수가 될 수 없다는 것을 이용
    // -1을 INF를 나타내는 입력으로 사용함
    for(auto it = costs.begin(); it != costs.end(); ++it){
        *it = -1;
    }

    // First : Vertex Weight (가중치), Second : Vectex ID Number
    // 가중치를 우선순위로 순회하며, 가중치가 같다면 더 앞에 있는 Vertex부터 순회한다
    priority_queue<pair<int, int>> pQue;
    pQue.push({0, startVertex});

    while(pQue.size() > 0){
        int vertex = pQue.top().second;
        // std::priority_queue가 Max Heap이기 때문에, Min Heap처럼 쓰기 위해 가중치에 -1을 곱해준다
        int weight = -pQue.top().first;

        pQue.pop();

        // 이미 최단 거리가 정해진 경로를 다시 갈 필요가 없기 때문에 건너 뛴다.
        if(costs[vertex] != -1){
            continue;
        }

        costs[vertex] = weight;

        vector<pair<int, int>> adjacentVertices = graph->adjacentPoints(vertex);

        // 각 인접 점에 대해 순회하자
        for(pair<int, int> adjacentVertex : adjacentVertices){
            int nextVertex = adjacentVertex.second;
            int costTotal = -adjacentVertex.first - costs[vertex];

            // 최단거리가 이미 정해진 곳
            if(costs[nextVertex] != -1){
                continue;
            }

            pQue.push({costTotal, nextVertex});
        }
    }
    return costs;
}

void test_Dijkstra() {

    int** map;
    int fieldRow;
    int fieldCol;

    std::cin >> fieldRow >> fieldCol;

    map = new int *[fieldRow];

    for (int j = 0; j < fieldRow; j++) {
        map[j] = new int[fieldCol];
        memset(map[j], 0, sizeof(int) * fieldCol);
    }

    for (int i = 0; i < fieldRow; i++) {
        for (int j = 0; j < fieldCol; j++) {
            std::cin >> map[i][j];
        }
    }

    GraphByMatrix<int>* graph = new GraphByMatrix<int>(map, fieldRow, fieldCol);

    std::vector<int> vt = Dijkstra(graph, 0);

    for (auto v : vt){
        std::cout << v << std::endl;
    }
}

#endif //SELFMADE_ALGORITHM_DIJKSTRA_H
