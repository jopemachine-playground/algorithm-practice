#include <string>
#include <vector>
#include <iostream>

using namespace std;

void search(vector<int>& numbers, int target, int idx, int sum, int& caseCnt) {
    if (idx >= numbers.size() - 1) {
        if ((sum + numbers[idx]) == target || (sum - numbers[idx] == target)) {
            ++caseCnt;
        }
        return;
    }
    
    search(numbers, target, idx + 1, sum + numbers[idx], caseCnt);
    search(numbers, target, idx + 1, sum - numbers[idx], caseCnt);
}

int solution(vector<int> numbers, int target) {
    int caseCnt = 0;
    search(numbers, target, 0, 0, caseCnt);
    return caseCnt;
}