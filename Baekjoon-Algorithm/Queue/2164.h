#include <iostream>
#include <queue>

using namespace std;

void solve(){
    int N;
    cin >> N;

    queue<int> que;

    for(int i = 1; i <= N; i++){
        que.push(i);
    }

    for(int i = 1; i < N; i++){

        que.pop();

        if(que.size() == 1) break;

        que.push(que.front());
        que.pop();

    }

    cout << que.front();


}
