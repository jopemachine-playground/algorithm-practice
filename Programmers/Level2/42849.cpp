#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int ym, yn;
    int ymSumYn = (brown - 4) / 2;

    for (int i = 1; i < ymSumYn; i++) {
        ym = i;
        yn = ymSumYn - ym;

        if (ym * yn == yellow) {
            answer.push_back(yn + 2);
            answer.push_back(ym + 2);
            break;
        }
    }
    return answer;
}