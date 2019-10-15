#include <iostream>

using namespace std;

void solve(){
    int N, R;
    string std;
    cin >> N;

    string res = "";

    for (int i = 0; i < N; i++){
        cin >> R >> std;
        for (int ii = 0; ii < std.size(); ii++) {
            for (int j = 0; j < R; j++)
                res += std[ii];
        }
        res += "\n";
    }

    cout << res;

}
