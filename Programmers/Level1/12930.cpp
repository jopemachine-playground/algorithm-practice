// https://programmers.co.kr/learn/courses/30/lessons/12930
#include <string.h>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";

    int index = 0;
    for (int i = 0; i < s.length(); i++){

        if(s.at(i) == ' ') {
            index = 0;
            answer += ' ';
            continue;
        }
        if(index % 2 == 0){
            answer += (toupper(s.at(i)));
            index++;
        }
        else {
            answer += (tolower(s.at(i)));
            index++;
        }
    }

    return answer;
}