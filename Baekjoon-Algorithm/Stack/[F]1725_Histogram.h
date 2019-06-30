/*
############################################################################
############################################################################
############################################################################
############################### Fail #######################################
############################################################################
############################################################################
############################################################################
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

// https://mygumi.tistory.com/177
// http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220781557098&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
// 아래와 같은 풀이 방법을 스위핑 알고리즘이라 한다고 함. (굉장히 어렵다고;;)
void solve_1725(){

    // 1 <= input <= 100,000
    int input = 0;

    cin >> input;

    // 높이의 범위가 int를 벗어날 수 있기 때문에, (20억 미만) int를 쓸 수 없음
    long long int* heightArray = new long long int[input];

    stack<long long int> stk;

    for (int i = 0; i < input; i++){
        cin >> heightArray[i];
    }

    long long int maxArea = heightArray[0];

    for (int i = 0; i < input; i++) {

        // 스택 top 보다 큰 높이가 들어오면 push
        // 위 조건으로 스택에는 오름차순으로 히스토그램이 생성된다
        if(stk.empty() || stk.top() <= heightArray[i]){
            stk.push(heightArray[i]);
        }
        // 스택 top 보다 작은 높이가 input으로 들어오면 특정 조건까지 pop
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

            // 위 과정을 거치고 들어온 input을 push 해 준다.
            stk.push(heightArray[i]);

        }
    }

    // 위 반복문이 끝나면 끝까지 한 번 훑은 것.
    // 이제 스택에 남아 있는 것들을 빼면서 다시 최대값 넓이를 검사한다.
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

    // maxArea < 20 * (10^8)(20억 미만)
    cout << maxArea;

}

// 스택 단원이지만, 스택을 안 쓰고 풀 수 있을 거 같아서 이렇게 구현해봄.
// 모든 사각형의 넓이를 구한 후 비교하기 때문에, 따지자면, Brute Force라고 해야할 것 같은데, input 크기가 너무 크기 때문에
// 당연하게도 시간초과가 난다
// 항상 문제를 풀기 전 입력의 범위를 확인하고, 어떤 알고리즘이 시간 초과되지 않을지 생각한 후에 문제를 풀도록 하자
void solve_1725_bruteForce() {

    // 1 <= input <= 100,000
    int input = 0;

    cin >> input;

    // 높이의 범위가 int를 벗어날 수 있기 때문에, (20억 미만) int를 쓸 수 없음
    long long int* heightArray = new long long int[input];

    for (int i = 0; i < input; i++){
        cin >> heightArray[i];
    }

    long long int maxArea = 0;

    // 두 점을 고르면 해당 직사각형의 넓이를 구할 수 있다.
    for (int leftPoint = 0; leftPoint < input; leftPoint++){
        for(int rightPoint = leftPoint; rightPoint < input; rightPoint++){

            // 구하는 직사각형의 넓이 중 높이는 가장 낮은 높이에 해당한다.
            long long int minHeight = heightArray[leftPoint];

            for (int heightIndex = leftPoint; heightIndex <= rightPoint; heightIndex++){
                if(minHeight > heightArray[heightIndex]){
                    minHeight = heightArray[heightIndex];
                }
            }

            // 구하는 직사각형의 넓이 중 너비는 두 값의 차에 해당한다.
            // leftPoint == rightPoint일 때 너비는 1에 해당함
            int width = rightPoint - leftPoint + 1;

            long long int area = width * minHeight;

            if (area > (long long int) maxArea) maxArea = area;
        }
    }

    // maxArea < 20 * (10^8)(20억 미만)
    cout << maxArea;

}
