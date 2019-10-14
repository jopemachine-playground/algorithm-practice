#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimeter){
    vector<string> vec;

    stringstream ss(str);

    string elem;

    while(getline(ss, elem, delimeter)){
        if(elem == "") continue;
        vec.push_back(elem);
    }

    return vec;
}

void solve(){
    string str;

    getline(cin, str);

    cout << ::split(str, ' ').size();
}
