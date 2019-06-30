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

// ȸ�� ������ �ð� ������ ������������ ����
int descendingCompare(const void* a, const void* b)
{
    int num1 = (*(pair<int, int>*) a).second;
    int num2 = (*(pair<int, int>*) b).second;

    if (num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;

    // ������ �ð��� ���ٸ� �����ϴ� �ð��� �̸� ������� �����ؾ� �Ѵ�
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


// ���� ���� �����ϸ鼭 ���� ���� ������ ȸ�� �ð��� ����
void solve_1931(){

    // N(1 �� N �� 100,000)
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

    // ȸ�� ������ �ð� ������ ������������ ����
    qsort(meetingTime, N, sizeof(pair<int, int>), descendingCompare);

    // �� �̻� ȸ�Ǹ� ������ �� ���� �� ���� �ݺ����� ����
    // ����ġ�� ȸ�ǰ� �����ϴ� �ð� + ȸ�� �ð����� ������, ����غ��� (int weight = meetingTime[i].first + (meetingTime[i].second - meetingTime[i].first);)
    // 'ȸ�ǰ� ������ �ð�'�� ���´�. ����, ȸ�ǰ� ���� ������ ������ ȸ�Ǹ� ������ (�׸��� �˰���)
    // ���ϴ� ����� ���� �� ���� ���̴�.
    for (int i = 0; i < N; i++){
        if(meetingTime[i].first >= currentTime){
            maxMeetingRoomNum++;
            currentTime = meetingTime[i].second;
        }
    }

    cout << maxMeetingRoomNum;

}


#endif //ALGORITHM_1931_MEETINGROOM_H
