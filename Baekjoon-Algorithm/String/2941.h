#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
    string input;
    cin >> input;

    vector<string> map = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (string str: map){
        while(true) {
            int n = input.find(str);

            if (n == string::npos) break;
            else input.replace(n, str.size(), " ");
        }
    }

    cout << input.size();
}
