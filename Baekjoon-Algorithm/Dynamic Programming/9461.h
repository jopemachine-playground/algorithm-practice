#include <iostream>
#include <array>
#include <set>

using namespace std;

long long int f[101];

void solve(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N;

        cin >> N;

        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        f[3] = 1;
        f[4] = 2;
        f[5] = 2;

        for (int i = 6; i <= N; i++) {
            f[i] = f[i - 1] + f[i - 5];
        }

        cout << f[N] << "\n";
    }
}
