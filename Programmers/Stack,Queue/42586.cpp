#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int length = progresses.size();
    int workCnt = 0;

    if (length == 0) {
        return answer;
    }

    if (length == 1) {
        answer.push_back(1);
        return answer;
    }
    
    int prevRemainingDate = -1;

    for (int i = 0; i < length; i++)
    {
        const int remaining = 100 - progresses[i];
        const int remainingDate = remaining % speeds[i] == 0 ? (remaining / speeds[i]) : (remaining / speeds[i]) + 1;

        if (prevRemainingDate < remainingDate) {   
            if (workCnt != 0) answer.push_back(workCnt);
            workCnt = 1;
            prevRemainingDate = remainingDate;
        }
        else {
            ++workCnt;
        }
        
        if (i == length - 1)
        {
            if (prevRemainingDate < remainingDate) {
                answer.push_back(1);
            }
            else {
                answer.push_back(workCnt);
            }

            break;
        }
    }

    return answer;
}