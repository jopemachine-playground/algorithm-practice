#include <iostream>

using namespace std;

void solve(){
    string input;
    cin >> input;

    int res = 0;
    int alphabets[26] = {
            3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10
    };
    for (int i = 0; i < input.size(); i++){
        res += ((alphabets[input[i] - 0x41]));
    }
    cout << res;

}

