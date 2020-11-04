#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    const int len = words.size();
    set<string> dict;
    
    dict.insert(words[0]);
    for (int i = 1; i < len; ++i) {
        const int order = (i % n) + 1;
        const int turn = (i / n) + 1;
        
        // check the word is in dict
        auto iter = dict.find(words[i]);
        if (iter != dict.end()) {
            answer.push_back(order);
            answer.push_back(turn);
            break;
        }

        // check the word is valid
        if (words[i].at(0) != words[i-1].at(words[i-1].length() - 1)) {
            answer.push_back(order);
            answer.push_back(turn);
            break;
        }
        
        dict.insert(words[i]);
    }
    
    if (answer.size() < 1) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}