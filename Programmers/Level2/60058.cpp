#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void reverseParenthesis(string &str)
{
    for (auto &ch : str)
    {
        if (ch == '(')
        {
            ch = ')';
        }
        else if (ch == ')')
        {
            ch = '(';
        }
    }
}

static int depth = 1;

bool isRightParenthesis(string p) {
    if (p.length() <= 1) return false;
    stack<char> stk;
    for (auto ch : p) {
        if (ch == '(') stk.push(ch);
        else {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    if (stk.empty()) return true;
    return false;
}

string recur(string p) {
    if (p == "") {
        return p;
    }

    // split u and v
    int Lcount = 0, Rcount = 0;
    
    string ustr = "";
    string vstr = "";

    for (int i = 0; i < p.length(); ++i) {
        if (p.at(i) == '(') ++Lcount;
        else if (p.at(i) == ')') ++Rcount;   

        if (Lcount == Rcount) {
            ustr = p.substr(0, i + 1);
            vstr = p.substr(i + 1);
            break;
        }
    }
    
    if (isRightParenthesis(ustr)) {
        return ustr + recur(vstr);
    }
    else {
        string result = "";
        result += "(";
        result += recur(vstr);
        result += ")";
        string reversed = ustr.substr(1, ustr.length() - 2);
        reverseParenthesis(reversed);
        result += reversed;
        
        return result;
    }
}

string solution(string p)
{
    if (isRightParenthesis(p)) return p;
    return recur(p);
}
