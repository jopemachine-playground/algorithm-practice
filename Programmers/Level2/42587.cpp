#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> que;
    
    for (int i = 0; i < priorities.size(); ++i) {
        que.push({ i, priorities[i] });
    }
    
    sort(priorities.begin(), priorities.end(), less<int>());
    
    int printCnt = 0;
    while (!que.empty()) {
        auto top = que.front();
        
        if (top.second >= priorities[priorities.size() - 1]) {
            if (top.first == location) {
                return ++printCnt;
            }
            else {
                ++printCnt;
                que.pop();
                priorities.pop_back();
            }
        }
        else {
            que.push(top);
            que.pop();
        }
    }
    

    return answer;
}