#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();

    // length should be greater than 0 and less than (len / 2) + 1
    for (int len = 1; len <= s.length() / 2; ++len) {
        string compressedStr = "";
        string repeatedStr = s.substr(0, len);
        int cnt = 1;

        for (int j = len; j <= s.length(); j += len) {
            if (repeatedStr == s.substr(j, len)) {
                ++cnt;
            }
            else {
                if (cnt == 1) {
                    compressedStr += repeatedStr;
                }
                else {
                    compressedStr += (to_string(cnt) + repeatedStr);
                }

                repeatedStr = s.substr(j, len);
                cnt = 1;
            }
        }

        if ((s.length() % len) != 0) {
            compressedStr += s.substr((s.length() / len) * len);
        }

        if (answer > compressedStr.length()) answer = compressedStr.length();
    }
    
    return answer;
}