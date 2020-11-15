#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    if (s.length() < 1) return false;

    stack<char> stk;
    
    for (auto ch : s) {
        if (ch == '(') {
            stk.push(ch);
        }
        else if (ch == ')') {
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
        }
    }

    if (stk.empty()) return true;

    return false;
}