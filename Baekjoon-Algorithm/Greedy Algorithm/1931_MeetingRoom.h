//
// Created by wonma on 2019-06-30.
//

#ifndef ALGORITHM_1931_MEETINGROOM_H
#define ALGORITHM_1931_MEETINGROOM_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

// 회의 끝나는 시간 순으로 내림차순으로 정렬
int descendingCompare(const void* a, const void* b)
{
    int num1 = (*(pair<int, int>*) a).second;
    int num2 = (*(pair<int, int>*) b).second;

    if (num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;

    // 끝나는 시간이 같다면 시작하는 시간이 이른 순서대로 정렬해야 한다
    else {
        int num1_1 = (*(pair<int, int>*) a).first;
        int num1_2 = (*(pair<int, int>*) b).first;

        if(num1_1 > num1_2){
            return 1;
        }
        else if(num1_1 < num1_2){
            return -1;
        }
        else {
            return 0;
        }
    }
}


// 가장 빨리 시작하면서 가장 빨리 끝나는 회의 시간을 고르자
void solve_1931(){

    // N(1 ≤ N ≤ 100,000)
    int N;
    cin >> N;

    pair<int, int> *meetingTime = new pair<int,int>[N];

    int currentTime = 0;
    int maxMeetingRoomNum = 0;
    int maxStartTime = 0;

    for (int i = 0; i< N; i++){
        cin >> meetingTime[i].first >> meetingTime[i].second;
        if(meetingTime[i].first > maxStartTime) maxStartTime = meetingTime[i].first;
    }

    // 회의 끝나는 시간 순으로 내림차순으로 정렬
    qsort(meetingTime, N, sizeof(pair<int, int>), descendingCompare);

    // 더 이상 회의를 진행할 수 없을 때 까지 반복문을 진행
    // 가중치를 회의가 시작하는 시간 + 회의 시간으로 잡으면, 계산해보면 (int weight = meetingTime[i].first + (meetingTime[i].second - meetingTime[i].first);)
    // '회의가 끝나는 시간'이 나온다. 따라서, 회의가 일찍 끝나는 순서로 회의를 잡으면 (그리디 알고리즘)
    // 원하는 결과를 얻을 수 있을 것이다.
    for (int i = 0; i < N; i++){
        if(meetingTime[i].first >= currentTime){
            maxMeetingRoomNum++;
            currentTime = meetingTime[i].second;
        }
    }

    cout << maxMeetingRoomNum;

}


#endif //ALGORITHM_1931_MEETINGROOM_H
