/*
==============================+===============================================================
@ File Name : 1725_Histogram.h
@ Author : jopemachine
@ Created Date : 2019-06-28, 20:45:25
@ Desc : 
@    히스토그램
==============================+===============================================================
*/
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
// �Ʒ��� ���� Ǯ�� ������ ������ �˰������̶� �Ѵٰ� ��. (������ ���ƴٰ�;;)
void solve_1725(){

    // 1 <= input <= 100,000
    int input = 0;

    cin >> input;

    // ������ ������ int�� ��� �� �ֱ� ������, (20�� �̸�) int�� �� �� ����
    long long int* heightArray = new long long int[input];

    stack<long long int> stk;

    for (int i = 0; i < input; i++){
        cin >> heightArray[i];
    }

    long long int maxArea = heightArray[0];

    for (int i = 0; i < input; i++) {

        // ���� top ���� ū ���̰� �������� push
        // �� �������� ���ÿ��� ������������ �������׷��� �����ȴ�
        if(stk.empty() || stk.top() <= heightArray[i]){
            stk.push(heightArray[i]);
        }
        // ���� top ���� ���� ���̰� input���� �������� Ư�� ���Ǳ��� pop
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

            // �� ������ ��ġ�� ������ input�� push �� �ش�.
            stk.push(heightArray[i]);

        }
    }

    // �� �ݺ����� ������ ������ �� �� ���� ��.
    // ���� ���ÿ� ���� �ִ� �͵��� ���鼭 �ٽ� �ִ밪 ���̸� �˻��Ѵ�.
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

    // maxArea < 20 * (10^8)(20�� �̸�)
    cout << maxArea;

}

// ���� �ܿ�������, ������ �� ���� Ǯ �� ���� �� ���Ƽ� �̷��� �����غ�.
// ���� �簢���� ���̸� ���� �� �����ϱ� ������, �����ڸ�, Brute Force���� �ؾ��� �� ������, input ũ�Ⱑ �ʹ� ũ�� ������
// �翬�ϰԵ� �ð��ʰ��� ����
// �׻� ������ Ǯ�� �� �Է��� ������ Ȯ���ϰ�, � �˰������� �ð� �ʰ����� ������ ������ �Ŀ� ������ Ǯ���� ����
void solve_1725_bruteForce() {

    // 1 <= input <= 100,000
    int input = 0;

    cin >> input;

    // ������ ������ int�� ��� �� �ֱ� ������, (20�� �̸�) int�� �� �� ����
    long long int* heightArray = new long long int[input];

    for (int i = 0; i < input; i++){
        cin >> heightArray[i];
    }

    long long int maxArea = 0;

    // �� ���� ������ �ش� ���簢���� ���̸� ���� �� �ִ�.
    for (int leftPoint = 0; leftPoint < input; leftPoint++){
        for(int rightPoint = leftPoint; rightPoint < input; rightPoint++){

            // ���ϴ� ���簢���� ���� �� ���̴� ���� ���� ���̿� �ش��Ѵ�.
            long long int minHeight = heightArray[leftPoint];

            for (int heightIndex = leftPoint; heightIndex <= rightPoint; heightIndex++){
                if(minHeight > heightArray[heightIndex]){
                    minHeight = heightArray[heightIndex];
                }
            }

            // ���ϴ� ���簢���� ���� �� �ʺ��� �� ���� ���� �ش��Ѵ�.
            // leftPoint == rightPoint�� �� �ʺ��� 1�� �ش���
            int width = rightPoint - leftPoint + 1;

            long long int area = width * minHeight;

            if (area > (long long int) maxArea) maxArea = area;
        }
    }

    // maxArea < 20 * (10^8)(20�� �̸�)
    cout << maxArea;

}
