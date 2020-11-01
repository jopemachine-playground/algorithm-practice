#include <string>
#include <vector>
#include <limits.h>   
#include <iostream>

using namespace std;

string solution(string s) {
    int min = INT_MAX;
    int max = INT_MIN;
    
    string inputBuffer = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (i == s.length() - 1) {
            inputBuffer.push_back(s.at(i));
        }

        if (s.at(i) == ' ' || i == s.length() - 1) {
            int num = stoi(inputBuffer);
            inputBuffer = "";
            
            if (min > num) min = num;
            if (max < num) max = num;
        }
        else {
            inputBuffer.push_back(s.at(i));
        }
 
    }

    string answer = to_string(min) + " " + to_string(max);
    return answer;
}