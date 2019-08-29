/*
==============================+===============================================================
@ File Name : 3986_Goodword.h
@ Author : jopemachine
@ Desc : 
@    좋은 단어
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

// 마지막에 스택이 clear 된다면 좋은 단어이고,
// 스택이 비어 있지 않다면 좋은 단어가 아니다.

void solve_3986() {

    int goodWords = 0;

    stack<char> stk;
    int inputNumber;
    cin >> inputNumber;

    string *strArray = new string[inputNumber];

    for (int i = 0; i < inputNumber; i++) {

        cin >> strArray[i];

        for (int j = 0; j < strArray[i].length(); j++) {
            if (!stk.empty() && stk.top() == strArray[i].at(j)) {
                stk.pop();
            } else {
                stk.push(strArray[i].at(j));
            }
        }
        if (stk.empty()) {
            goodWords++;
        }
        while(!stk.empty()){
            stk.pop();
        }
    }

    cout << goodWords;
}
