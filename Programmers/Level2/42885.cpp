#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), less<int>());
    
    int sIdx = 0;
    int eIdx = people.size() - 1;
    
    while (eIdx >= sIdx) {        
        // most fat people's weight + least fat people's weight
        if (people[sIdx] + people[eIdx] > limit) {
            // remove most fat person
            --eIdx;
        }
        else {
            // remove most fat person and least fat person
            ++sIdx;
            --eIdx;
        }
        ++answer;
    }
    
    return answer;
}