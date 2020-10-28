#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define DEBUG

class NumInfo {
public:
    int index;
    int number;
    int original;
};

string solution(vector<int> numbers) {
    string answer = "";

    // index, number value
    vector<NumInfo> numIdxs;
    int idx = 0;
    for (auto number : numbers) {
        int original = number;
        int lastNum = number % 10;

        if (number < 10) {
            number = number * 1000 + lastNum * 111;
        }
        else if (10 <= number && number < 100) {
            number = number * 100 + lastNum * 11;
        }
        else if (100 <= number && number < 1000) {
            number = number * 10 + lastNum;
        }

        numIdxs.push_back(NumInfo { idx, number, original });
    }

    sort(numIdxs.begin(), numIdxs.end(), [] (NumInfo ls, NumInfo rs) -> bool {
        if (ls.number == rs.number) {
            return ls.original < rs.original;
        }
        return ls.number > rs.number;
    });

    #ifdef DEBUG
    for (auto numIdx : numIdxs) {
        cout << numIdx.second << endl;
    }
    #endif

    for (auto numIdx : numIdxs) {
        answer += to_string(numbers[numIdx.first]);
    }

    return answer;
}