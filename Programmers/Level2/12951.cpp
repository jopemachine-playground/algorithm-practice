#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirstCh = true;
    for (int i = 0; i < s.length(); ++i) {
        if (isFirstCh && s.at(i) != ' ') {
            isFirstCh = false;
            answer += toupper(s.at(i));
            continue;
        }

        if (s.at(i) == ' ') {
            isFirstCh = true;
        }
        
        answer += tolower(s.at(i));
    }

    return answer;
}