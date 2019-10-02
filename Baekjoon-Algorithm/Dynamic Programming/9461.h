/*
==============================+===============================================================
@ File Name : 9461.h
@ Author : jopemachine
@ Desc : 
@    파도반 수열
@    규칙성만 찾으면 간단히 풀 수 있는 문제.
@    피보나치 수열과 비슷한 점화식을 갖고 있음.
==============================+===============================================================
*/
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
