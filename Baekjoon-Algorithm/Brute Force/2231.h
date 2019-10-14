#include <iostream>

using namespace std;

void solve(){
    string Nstr;
    cin >> Nstr;

    Nstr.size();
    int N = atoi(Nstr.c_str());

    int sum;
    int minGen = 0;
    for(int i = N; i > N - 9 * Nstr.size(); i--){
        sum = i;
        string num = to_string(i);
        for(int j = 0; j < num.size(); j++){
           sum += num.at(j) - '0';
        }
        if(sum == N){
            minGen = i;
        }
    }

    cout << minGen;

}

