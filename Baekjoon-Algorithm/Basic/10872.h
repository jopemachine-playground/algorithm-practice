#include <iostream>

using namespace std;

void solve(){
    int N;
    cin >> N;
    int R = 1;
    for(int i = 1; i <= N; i++){
        R *= i;
    }
    cout << R;
}

