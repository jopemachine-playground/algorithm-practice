#ifndef SELFMADE_ALGORITHM_DIJKSTRA_H
#define SELFMADE_ALGORITHM_DIJKSTRA_H

#include <queue>
#include "../../Data-Structure/Graph/GraphByMatrix.h"

using namespace std;

// �켱���� ť�� �̿��� ���ͽ�Ʈ�� �˰��� ����
// https://jason9319.tistory.com/307 �� ���鼭 ���� �����ߴ�

vector<int> Dijkstra(GraphByMatrix<int>* graph, int startVertex){

    // ������ �ּҺ�� �ڽ�Ʈ vector
    vector<int> costs(graph->row());

    // ���ͽ�Ʈ�� �˰��򿡼� ����ġ�� ������ �� �� ���ٴ� ���� �̿�
    // -1�� INF�� ��Ÿ���� �Է����� �����
    for(auto it = costs.begin(); it != costs.end(); ++it){
        *it = -1;
    }

    // First : Vertex Weight (����ġ), Second : Vectex ID Number
    // ����ġ�� �켱������ ��ȸ�ϸ�, ����ġ�� ���ٸ� �� �տ� �ִ� Vertex���� ��ȸ�Ѵ�
    priority_queue<pair<int, int>> pQue;
    pQue.push({0, startVertex});

    while(pQue.size() > 0){
        int vertex = pQue.top().second;
        // std::priority_queue�� Max Heap�̱� ������, Min Heapó�� ���� ���� ����ġ�� -1�� �����ش�
        int weight = -pQue.top().first;

        pQue.pop();

        // �̹� �ִ� �Ÿ��� ������ ��θ� �ٽ� �� �ʿ䰡 ���� ������ �ǳ� �ڴ�.
        if(costs[vertex] != -1){
            continue;
        }

        costs[vertex] = weight;

        vector<pair<int, int>> adjacentVertices = graph->adjacentPoints(vertex);

        // �� ���� ���� ���� ��ȸ����
        for(pair<int, int> adjacentVertex : adjacentVertices){
            int nextVertex = adjacentVertex.second;
            int costTotal = -adjacentVertex.first - costs[vertex];

            // �ִܰŸ��� �̹� ������ ��
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
