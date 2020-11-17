#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int stiringCnt = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int i = 0; i < scoville.size(); ++i) {
        pq.push(scoville[i]);
    }
    
    while (pq.size() >= 2) {
        int leastK = pq.top();
        if (leastK >= K) break;
        pq.pop();
        int secondLeastK = pq.top();
        pq.pop();
        
        ++stiringCnt;
        int newK = leastK + 2 * secondLeastK;
        pq.push(newK);
    }
    
    if (pq.size() == 1 && pq.top() < K) return -1;

    return stiringCnt;
}