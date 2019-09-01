/*
==============================+===============================================================
@ File Name : 10610_30.h
@ Author : jopemachine
@ Desc : 
@    30의 배수라면 3의 배수이면서 10의 배수이다.
@    3의 배수이면 각 자리 수의 합이 3의 배수이며, 10의 배수라면 자릿 수 중 하나 이상의 값이 0이여야 한다.
@    이 두 조건을 만족하면 각 자릿 수를 내림차순으로 정렬한 수가 찾는 수 중 제일 큰 수이다.
@    
@    입력 범위를 잘 안 보고 풀었다가 틀리고 나서야 long long int에도 담을 수 없는 큰 수가 입력이 될 수 있다는 걸 알고
@    1번으로 다시 풀었다. 처음에 풀었던 것은 버리지 않고 2번 풀이로 뒀다.
==============================+===============================================================
*/

#ifndef SELFMADE_ALGORITHM_10610_30_H
#define SELFMADE_ALGORITHM_10610_30_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

int descendingCompare(const void* a, const void* b)
{
    int num1 = *(int*) a;
    int num2 = *(int*) b;

    if (num1 > num2)
        return -1;
    else if (num1 < num2)
        return 1;
    else return 0;
}

void solve_10610(){

    char N[1000000];
    scanf("%s", N);
    int digits = strlen(N);

    int *digit_k = new int[1000000];

    long long int sum = 0;

    bool isMultipleOfThree = false;
    bool isMultipleOfTen   = false;

    for(int i = 0; i < digits; i++){
        digit_k[i] = N[i] - '0';
        sum       += digit_k[i];
        if(digit_k[i] == 0) isMultipleOfTen = true;
    }

    if(sum % 3 == 0) isMultipleOfThree = true;

    if(isMultipleOfThree && isMultipleOfTen){
        qsort(digit_k, digits, sizeof(int), descendingCompare);
        for(int i = 0; i < digits; i++) printf("%d", digit_k[i]);
    }
    else {
        cout << -1;
    }

    delete digit_k;
}

void solve_10610_2(){

    long long int N;
    cin >> N;

    long long int tempN = N;

    // digits <= 10^5
    int digits = 1;
    while((tempN /= 10) >= 1) digits++;

    // 0 <= digit <= 9
    int digit_k[digits];

    digit_k[0] =  N % 10;

    long long int sum = digit_k[0];

    bool isMultipleOfTen = digit_k[0] == 0 ? true : false;

    for(int i = 1; i < digits; i++){
        long long int a = (N % (long long int) pow(10, i + 1));
        long long int b = (N % (long long int)pow(10, i));
        long long int c = (long long int) pow(10, i);

        digit_k[i] = (a - b) / c;
        sum += digit_k[i];
        if(digit_k[i] == 0) {
            isMultipleOfTen    = true;
        }
    }

//    for(int i = digits - 1; i >= 0 ; i--){
//        cout << digit_k[i] << "\n";
//    }
    bool isMultipleOfThree = (sum % 3 == 0);

    if(isMultipleOfTen && isMultipleOfThree){
        qsort(digit_k, digits, sizeof(int), descendingCompare);
        for(int i = 0; i < digits; i++) printf("%d", digit_k[i]);
    }
    else{
        cout << -1;
    }


}

#endif //SELFMADE_ALGORITHM_10610_30_H
