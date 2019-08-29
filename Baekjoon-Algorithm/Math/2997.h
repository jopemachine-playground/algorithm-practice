/*
==============================+===============================================================
@ File Name : 2997.h
@ Author : jopemachine
@ Desc : 
@    네 번째 수
==============================+===============================================================
*/

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

// 4���� ���ڰ� �־����µ�, �� ���ڵ��� ���������� �̷��� ���ڵ��̴�.
// ���� �� ���ڴ� ���ĵǾ� ���� ���� �� �ִ�.
// �Ҿ����� ���ڸ� ���ض�. (���� ���� �� �� �� �ִ�)
void solve_2997(){

    // �Ҿ����� ���ڸ� a[3]�� ����
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
