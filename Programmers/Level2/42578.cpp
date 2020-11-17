#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> map;
    
    for (vector<string> cloth : clothes) {
        // clothes.push_back();
        auto iter = map.find(cloth[1]);
        if (iter == map.end()) {
            map.insert({ cloth[1], 1 });
        }
        else {
            map[cloth[1]] = map[cloth[1]] + 1;
        }
    }
    
    int multiplier = 1;
    for (auto cloth : map) {
        // 안 입는 경우의 수 추가
        multiplier *= (cloth.second + 1);
    }
    
    // 모두 안 입는 경우 제외
    answer += (multiplier - 1);

    return answer;
}