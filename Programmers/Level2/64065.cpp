#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> numbers;

    string numBuf = "";
    vector<int> elemVec = vector<int>();

    // parsing (excluding most outer bracket)
    for (int i = 1; i < s.length() - 1; i++) {
        if (s.at(i) == ',' && s.at(i-1) == '}') {
            continue;
        }

        if(s.at(i) == '{') {
            elemVec = vector<int>();
        }
        else if (s.at(i) == '}' || s.at(i) == ',') {
            elemVec.push_back(stoi(numBuf));
            numBuf = "";
            if (s.at(i) == '}') numbers.push_back(elemVec);
        }
        else {
            numBuf += s.at(i);
        }
    }
    
    sort(numbers.begin(), numbers.end(), [](vector<int> v1, vector<int> v2) -> bool {
        return v1.size() < v2.size();
    });
    
    
    // do brute force (O(n^3))
    answer.push_back(numbers[0][0]);

    for (int i = 1; i < numbers.size(); ++i) {
        auto arr = numbers[i];
        for (int j = 0; j < numbers[i - 1].size(); ++j) {
            for (int k = 0; k < arr.size(); ++k) {
                if (numbers[i - 1][j] == arr[k]) {
                    arr[k] = -1;
                    break;
                }
            }
        }

        int target = -1;
        for (int k = 0; k < arr.size(); ++k) {
            if (arr[k] != -1) target = arr[k];
        }
        answer.push_back(target);
    }
    

    return answer;
}