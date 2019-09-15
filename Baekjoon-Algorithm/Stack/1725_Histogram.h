/*
==============================+===============================================================
@ File Name : 1725_Histogram.h
@ Author : jopemachine
@ Desc : 
@    ** Fail **
@    히스토그램
@    풀다 일단 포기함. 세그먼트 트리란 자료구조를 이용해야 한다고 함.
@ Ref URLs : 
@    https://mygumi.tistory.com/177
@    http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220781557098&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
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

void solve_1725(){

    // 1 <= input <= 100,000
    int input = 0;

    cin >> input;

    long long int* heightArray = new long long int[input];

    stack<long long int> stk;

    for (int i = 0; i < input; i++){
        cin >> heightArray[i];
    }

    long long int maxArea = heightArray[0];

    for (int i = 0; i < input; i++) {

        if(stk.empty() || stk.top() <= heightArray[i]){
            stk.push(heightArray[i]);
        }

        else if (stk.top() > heightArray[i]){

            int width = 1;

            int heightIndex = i - 1;

            while(!stk.empty()){

                long long int area;

                if(stk.size() == 1){
                    area = width * stk.top() + heightIndex;

                    int selectedWidth = i - 1;

                    while(heightArray[i] > heightArray[selectedWidth]){
                        selectedWidth--;
                    }

                    if (area < (selectedWidth) * heightArray[i]) {
                        area = (selectedWidth) * heightArray[i];
                    }

                    // if(area < i - heightIndex) area += i - heightIndex;
                }
                else{
                    area = width * stk.top();
                }

                stk.pop();

                if(area > maxArea) maxArea = area;

                width++;
                heightIndex--;
            }


            stk.push(heightArray[i]);

        }
    }


    int endWidth = 1;

    while(!stk.empty()){

        long long int h = stk.top();

        if(maxArea < h * endWidth){
            maxArea = h * endWidth;
        }

        stk.pop();

        long long int area = endWidth * h;

        if(area > maxArea) maxArea = area;

        endWidth++;
    }

    cout << maxArea;

}

void solve_1725_bruteForce() {

    // 1 <= input <= 100,000
    int input = 0;

    cin >> input;


    long long int* heightArray = new long long int[input];

    for (int i = 0; i < input; i++){
        cin >> heightArray[i];
    }

    long long int maxArea = 0;

    for (int leftPoint = 0; leftPoint < input; leftPoint++){
        for(int rightPoint = leftPoint; rightPoint < input; rightPoint++){

            long long int minHeight = heightArray[leftPoint];

            for (int heightIndex = leftPoint; heightIndex <= rightPoint; heightIndex++){
                if(minHeight > heightArray[heightIndex]){
                    minHeight = heightArray[heightIndex];
                }
            }

            int width = rightPoint - leftPoint + 1;

            long long int area = width * minHeight;

            if (area > (long long int) maxArea) maxArea = area;
        }
    }

    cout << maxArea;

}
