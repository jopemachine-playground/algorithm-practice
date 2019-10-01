#include <iostream>
#include <array>
#include <set>

using namespace std;

int f[1001];

void solve(){
   int N;
   cin >> N;

   f[0] = 0;
   f[1] = 1;
   f[2] = 3;

   for (int i = 3; i <= 1000; i++){
       f[i] = (f[i-1] + f[i-2] * 2) % 10007;
   }

   cout << f[N];
}

