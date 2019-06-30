//
// Created by wonma on 2019-06-30.
//

#ifndef ALGORITHM_2997_H
#define ALGORITHM_2997_H
#include <iostream>

using namespace std;

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 > num2) {
        return 1;
    }

    if (num1 < num2) {
        return -1;
    }

    return 0;
}

// 4개의 숫자가 주어졌는데, 이 숫자들은 등차수열을 이루는 숫자들이다.
// 남은 세 숫자는 정렬되어 있지 않을 수 있다.
// 잃어버린 숫자를 구해라. (답이 여러 개 일 수 있다)
void solve_2997(){

    // 잃어버린 숫자를 a[3]에 저장
    int a[4];
    int diff[3];
    int realDiff;

    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }

    // quick sort
    qsort(a, 3, sizeof(int), compare);

    diff[0] = a[1] - a[0];
    diff[1] = a[2] - a[1];

    realDiff = min(abs(diff[0]), abs(diff[1]));

    if(diff[0] > diff[1]){
        a[3] = a[0] + realDiff;
    }
    else if(diff[0] < diff[1]){
        a[3] = a[1] + realDiff;
    }
    else {
        a[3] = a[2] + realDiff;
    }

    cout << a[3];

}

#endif //ALGORITHM_2997_H
