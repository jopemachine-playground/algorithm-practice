/*
==============================+===============================================================
@ File Name : 1874_stackSequence.h
@ Author : jopemachine
@ Desc : 
@    스택 수열
==============================+===============================================================
*/
#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

void solve_1874() {
    // Prev:: 1 <= n <= 100,000
    stack<int> stk;

    int inputNumber;
    cin >> inputNumber;

    int maxValue = 0;
    int* inputArray = new int[inputNumber];
    string result = "";

    int maxIndex = -1;

    for (int i = 0; i < inputNumber; i++) {
        cin >> inputArray[i];
        if (inputArray[i] == inputNumber) maxIndex = i;
    }

    for (int i = maxIndex; i < inputNumber - 1; i++) {
        if (!(inputArray[i] > inputArray[i + 1])) {
            result = "NO";
            break;
        }
    }

    if (result != "NO") {
        for (int i = 0; i < inputNumber; i++) {

            // push
            if (stk.empty() || (stk.top() < inputArray[i])) {
                if (inputArray[i] < maxValue) {
                    result = "NO";
                    break;
                }
                for (int j = 1; j < inputArray[i] - maxValue + 1; j++) {
                    stk.push(maxValue + j);
                    result += "+\n";
                }
                stk.pop();
                result += "-\n";
                if (maxValue < inputArray[i]) maxValue = inputArray[i];
            }

            else if (!stk.empty() && (stk.top() > inputArray[i])) {
                for (int j = 0; j < stk.top() - inputArray[i] + 1; j++) {
                    stk.pop();
                    result += "-\n";
                }
            }

            else if(stk.top() == inputArray[i]){
                stk.pop();
                result += "-\n";
            }
        }
    }

    cout << result;
}