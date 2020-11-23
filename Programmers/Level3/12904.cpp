#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int solution(string s)
{
    int answer = 1;
    // to avoid core dumped, need to push 1 dummy character.
    s.push_back('0');

    for (int i = 1; i < s.length(); ++i) {
        int s_Idx = i - 1, e_Idx = i + 1, evenLen = 0, oddLen = 1;
        bool evenDone = false, oddDone = false;

        while (s_Idx > 0 ||
               e_Idx < s.length())
        {   
            // evenCase
            if (s[s_Idx] == s[e_Idx - 1]) {
                evenLen += 2;
            }
            else evenDone = true;
            // oddCase
            if (s[s_Idx] == s[e_Idx]) {
                oddLen += 2;
            }
            else oddDone = true;
            
            if (oddDone && evenDone) break;
            --s_Idx; ++e_Idx;
        }

        int len = (evenLen > oddLen) ? evenLen : oddLen;
        if (answer < len) answer = len;
    }
    
    return answer;
}