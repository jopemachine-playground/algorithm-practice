#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int number = n;
    
    // false = 0, true = 1
    bool digits[20 + 1] = { false,};
        
    static int cache[20];
    
    cache[0] = 1;
    for (int i = 1; i < 20; ++i) {
        cache[i] = cache[i - 1] << 1;  
    }
    
    // apply from big number
    int mostLeastOneIdx = -1;
    for (int i = 19; i >= 0; --i) {
        // mark 1. (0 is default).
        if (number >= cache[i]) {
            digits[i] = true;
            number -= cache[i];
            mostLeastOneIdx = i;
        }
    }
    
    // find zero next to the smallest one.
    int mostLeastZeroIdx = 20;
    for (int i = mostLeastOneIdx + 1; i < 20; ++i) {
        if (digits[i] == false) {
            mostLeastZeroIdx = i;
            break;
        }
    }
    
    // swap most least 1 and 0
    digits[mostLeastOneIdx] = 0;
    digits[mostLeastZeroIdx] = 1;
    
    // find all 1 under 'digits[mostLeastZeroIdx]', mark it false.
    int oneCnt = 0;
    for (int i = 0; i < mostLeastZeroIdx; ++i) {
        if (digits[i] == true) {
            ++oneCnt;
            digits[i] = false;
        }
    }
    
    // mark true 
    for (int i = 0; i < oneCnt; ++i) {
        digits[i] = true;
    }
    
    // make answer 
    int answer = 0;
    for (int i = 0; i < 20; ++i) {
        if (digits[i] == true)
            answer += 1 << i;
    }
    
    return answer;
}