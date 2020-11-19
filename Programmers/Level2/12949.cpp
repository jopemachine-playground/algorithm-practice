#include <algorithm>
#include <sstream>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <numeric>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <array>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < arr1.size(); ++i) {    
        vector<int> vec;
        for (int j = 0; j < arr2[0].size(); ++j) {
            int sum = 0;
            for (int k = 0; k < arr1[i].size(); ++k) {
                sum += (arr1[i][k] * arr2[k][j]);
            }
            vec.push_back(sum);
        }
        answer.push_back(vec);
    }
    
    return answer;
}