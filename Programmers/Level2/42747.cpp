#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    const int n = citations.size();

    sort(citations.begin(), citations.end(), greater<int>());

    int i = 0;
    for (; i < n; ++i) {
        if (i >= citations[i]) {
            break;
        }
    }

    return i;
}