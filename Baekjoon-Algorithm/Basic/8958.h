#ifndef ALGORITHM_8958_H
#define ALGORITHM_8958_H

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(){

    int T;
    cin >> T;

    deque<int> que;

    for (int i = 0; i < T; i++){
        que.push_back(0);
        string input = "";
        cin >> input;
        transform(input.begin(), input.end(),
                std::back_inserter(que),
                [&que](const char OorX)-> int { return OorX == 'X' ? 0 : que.back() + 1;});
        cout << accumulate(que.begin(), que.end(), 0) << "\n";
        que.clear();
    }

}
#endif //ALGORITHM_8958_H
