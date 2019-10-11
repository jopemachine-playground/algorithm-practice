#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = false;
    std::string x_s = to_string(x);

    int sum= 0;
    for(int i = 0; i < x_s.length(); i++){
        sum += (x_s.at(i) - '0');
    }

    if(x % sum == 0) answer = true;

    return answer;
}