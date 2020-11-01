#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for (auto ch : s) {
        if (ch == '(') {
            stk.push(ch);
        }
        else if (ch == ')') {
            if (stk.top() != '(') {
                return false;
            }
            stk.push(ch);
        }
    }

    if (stk.empty()) return true;

    return false;
}