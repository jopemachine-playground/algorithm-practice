#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> set;
    
    sort(phone_book.begin(), phone_book.end(), [](string a, string b) -> bool {
        return a.length() < b.length();
    });
    
    for (int i = 0; i < phone_book.size(); ++i) {
        for (int j = 0; j < phone_book[i].size(); ++j) {
            string ss = phone_book[i].substr(0, j + 1);
            auto iter = set.find(ss);
            // find 
            if (iter != set.end()) {
                return false;
            }
        }
        set.insert(phone_book[i]);
    }
    
    return true;
}