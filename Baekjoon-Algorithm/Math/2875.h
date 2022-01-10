#include <iostream>

using namespace std;

int main(){
    int R;

    int N, M, K;
    cin >> N >> M >> K;

    int W;
    while(K-- > 0){
        if(N > 2 * M) N--;
        else M--;
    }

    if(N > 2 * M) R = M;
    else R = N / 2;
    cout << R;
}