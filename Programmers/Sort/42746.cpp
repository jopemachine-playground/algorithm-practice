#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//#define DEBUG

class NumInfo {
public:
    int index;
    int number;
};

string solution(vector<int> numbers) {
    string answer = "";

    // index, number value
    vector<NumInfo> numInfos;
    int idx = 0;

    for (auto number : numbers) {
        if (number < 10) {
            number = number * 1000 + number * 111;
        }
        else if (10 <= number && number < 100) {
            number = number * 100 + number;
        }
        else if (100 <= number && number < 1000) {
            number = number * 10 + (number / 100);
        }

        numInfos.push_back(NumInfo{ idx++, number });
    }
    
    sort(numInfos.begin(), numInfos.end(), [] (NumInfo ls, NumInfo rs) -> bool {
        return ls.number > rs.number;
    });

    #ifdef DEBUG
    for (auto numInfo : numInfos) {
        cout << numInfo.number << endl;
    }
    #endif

    bool firstZero = true;
    for (auto numInfo : numInfos) {
        if (numbers[numInfo.index] != 0) {
            firstZero = false;
        }
        if (!firstZero) {
            answer += to_string(numbers[numInfo.index]);
        }
    }
    
    if (numbers.size() == 0) return "";
    if (firstZero) return "0";

    return answer;
}