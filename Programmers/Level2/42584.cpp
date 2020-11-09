#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer = vector<int>(prices.size());
    stack<pair<int,int>> stk;
    
    for (int i = prices.size() - 2; i >= 0; --i) {
        int day = 0;
        
        while (!stk.empty() && stk.top().first >= prices[i]) {
            day += stk.top().second;
            stk.pop();
        }
        
        stk.push({ prices[i], day + 1 });
        answer[i] = day + 1;
    }
    
    return answer;
}