#include <iostream>
#include <algorithm>

using namespace std;

string reverse(string str){

    string result = "";
    result.reserve(str.size());

    for(int i = 0; i < str.size(); i++){
        result += str[str.size() - i - 1];
    }
    return result;

}

void solve(){
    int inputInt[2];
    string inputs[2];
    cin >> inputs[0] >> inputs[1];

    inputInt[0] = atoi(::reverse(inputs[0]).c_str());
    inputInt[1] = atoi(::reverse(inputs[1]).c_str());

    cout << *max_element(inputInt, inputInt + 2);

}
