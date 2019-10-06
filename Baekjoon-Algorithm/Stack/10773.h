#include <iostream>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

void solve(){
    int K;
    stack<int> stk;

    cin >> K;

    int t;
    for(int i = 0; i < K; i++) {
        cin >> t;
        if (t == 0)
            stk.pop();
        else
            stk.push(t);
    }

    int sum = 0;
    while(!stk.empty()){
        sum += stk.top();
        stk.pop();
    }

    cout << sum;

}

