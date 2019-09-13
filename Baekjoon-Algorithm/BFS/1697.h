/*
==============================+===============================================================
@ File Name : 1697.h
@ Author : jopemachine
@ Desc : 
@    숨바꼭질
@    항상 bfs, dfs는 이차원 배열로 나타나는 그래프에서만 사용해봐서 이 문제가 bfs로 풀 수 있는 유형이란 걸 몰랐다.
@    
@    수민이가 할 수 있는 행동들을 트리 (또는 그래프) 로 만들어서 완전탐색 하면서 도착지에 도달할 수
@    있는지 보겠다는 것으로 봐도 될 것 같다.
@ Ref URLs : 
@    https://hsp1116.tistory.com/20
==============================+===============================================================
*/
#ifndef ALGORITHM_1697_H
#define ALGORITHM_1697_H

#include <iostream>
#include <queue>

using namespace std;

// 0<= N, K <= 100,000
const int MAX = 100001;

// static int time = 0;
int N, K;
queue<int> que;

// Array Init
int visited[MAX] = {0,};

int bfs(){
    que.push(N);

    visited[N] = 1;

    while(true){

        int pos = que.front();

        // -1 Because of starting from 1 at point n
        if(visited[K] != 0) return visited[K] - 1;

        if(pos + 1 <= MAX && visited[pos + 1] == 0){
            que.push(pos + 1);
            visited[pos + 1] = visited[pos] + 1;
        }
        if(pos - 1 >= 0   && visited[pos - 1] == 0){
            que.push(pos - 1);
            visited[pos - 1] = visited[pos] + 1;
        }
        if(pos * 2 <= MAX && visited[pos * 2] == 0){
            que.push(pos * 2);
            visited[pos * 2] = visited[pos] + 1;
        }

        que.pop();
    }
}

void solve_1697(){

    cin  >> N >> K;
    cout << bfs();

}

#endif //ALGORITHM_1697_H
