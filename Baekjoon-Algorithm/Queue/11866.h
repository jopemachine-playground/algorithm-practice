#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> que;

void solve(){
    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++){
        que.push(i + 1);
    }

    vector<int> res;
    while(!que.empty()){

        for(int i = 0; i < K - 1; i++){
            que.push(que.front());
            que.pop();
        }

        res.push_back(que.front());
        que.pop();
    }

    cout << "<";
    for (int i = 0; i < N; i++){
        cout << res[i];
        if(i != N - 1) cout << ", ";
    }
    cout << ">";


}
