// https://js1jj2sk3.tistory.com/38
#include <iostream>

using namespace std;

int f[101];

void solve(){
    int N;
    cin >> N;

    f[0] = 0;
    f[1] = 9;
    f[2] = 17;

    for(int i = 2; i <= N; i++){
        f[i] = (2 * f[i-1] - (i - 1)) % 1000000000;
    }

    cout << f[N];

}
