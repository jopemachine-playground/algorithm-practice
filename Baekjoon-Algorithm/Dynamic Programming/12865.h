/*
==============================+===============================================================
@ File Name : 12865.h
@ Author : jopemachine
@ Desc : 
@    ** Fail **
@    평범한 배낭 (배낭 문제).
@    DP 문제라는데 어떻게 풀 지 도저히 모르겠어서 종만북을 코드를 참고해 풀었다.
@    물건을 담지 않으면 pack(allItems, cache, capacity, index + 1, itemMaxNumber)가 ret,
@    물건을 담으면 위와 pack(allItems, cache, capacity - allItems[index].weight, index + 1, itemMaxNumber) + allItems[index].value)가
@    ret가 되므로 둘 중 큰 값을 ret로 하고 리턴하면 완전 탐색되어 풀린다.
@    중요한 것은 ret를 캐시에 저장해서 메모리제이션 할 것.
@ Ref URLs : 
@    프로그래밍 대회에서 배우는 알고리즘 해결 전략 284 페이지
==============================+===============================================================
*/

#ifndef ALGORITHM_12865_H
#define ALGORITHM_12865_H

#include <iostream>
#include <algorithm>
#include <array>
#include <memory.h>

using namespace std;

int N, K;

void debug(int** cache);

typedef struct{
    int value;
    int weight;
} Item;

int pack(const Item* allItems, int** cache, const int capacity, const int index, const int itemMaxNumber){
    if(index == itemMaxNumber){
        return 0;
    }

    int& ret = cache[capacity][index];
    if(ret != -1) return ret;

    ret = pack(allItems, cache, capacity, index + 1, itemMaxNumber);

    if(capacity >= allItems[index].weight) {
        ret = max(ret,
                  pack(allItems, cache, capacity - allItems[index].weight, index + 1, itemMaxNumber) +
                  allItems[index].value);
    }

    return ret;
}

void solve_12865(){

    cin >> N >> K;

    Item items[N];

    int** cache = new int*[K + 1];

    for(int i = 0; i < K + 1; i++){
        cache[i] = new int[N];
        memset(cache[i], -1, sizeof(int) * (N));
    }

    for(int i = 0; i < N; i++){
        cin >> items[i].weight >> items[i].value;
    }

    cout << pack(items, cache, K, 0, N);

    debug(cache);

}

void debug(int** cache){
    for(int i= 0; i < K + 1; i++){
        for(int j = 0; j < N; j++){
            cout << cache[i][j] << " ";
        }
        cout << "\n";
    }
}

#endif //ALGORITHM_12865_H
