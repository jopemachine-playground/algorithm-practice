//
// Created by wonma on 2019-07-01.
//
#pragma once

#include <iostream>
#include <vector>
#include <memory.h>

#ifndef SELFMADE_ALGORITHM_GRAPHBYMATRIX_H
#define SELFMADE_ALGORITHM_GRAPHBYMATRIX_H

template<class T, class Allocator = std::allocator<T>>
class GraphByMatrix {

public:

    GraphByMatrix(T **_graph, int _rowSize, int _colSize) : rowSize(_rowSize), colSize(_colSize) {
        graph = new T *[rowSize];
        for (int i = 0; i < rowSize; i++) {
            graph[i] = new T[colSize];
        }

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                graph[i][j] = _graph[i][j];
            }
        }
    }

    void print() {
        for (int j = 0; j < rowSize; j++) {
            for (int k = 0; k < colSize; k++) {
                std::cout << graph[j][k] << " ";
            }
            std::cout << "\n";
        }
    }

    std::vector<std::pair<T, int>> adjacentPoints(int vertex) {
        std::vector<std::pair<int, T>> vt;

        for (int i = 0; i < colSize; i++) {
            if (graph[vertex][i] > 0) {
                vt.push_back(std::make_pair(graph[vertex][i], i));
            }
        }
        return vt;
    }

    int row() {
        return rowSize;
    }

    int col() {
        return colSize;
    }

private:

    T **graph;

    int rowSize;

    int colSize;

};

/*
void testGraph(){

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


    GraphByMatrix<int>* graph = new GraphByMatrix<int>(map, fieldRow, fieldCol);\
        graph->print();

    }
  */



#endif //SELFMADE_ALGORITHM_GRAPHBYMATRIX_H
