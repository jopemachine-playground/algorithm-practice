#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct {
    bool isZero;
    bool allSame;
} Arg;

Arg checkAllSame(vector<vector<int>>& arr, int sIdx_x, int sIdx_y, int len) {
    bool allOne = true;
    bool allZero = true;

    for (int y = sIdx_y; y < sIdx_y + len; ++y) {
        for (int x = sIdx_x; x < sIdx_x + len; ++x) {
            if (allOne && arr[y][x] == 0) {
                allOne = false;
            }
            if (allZero && arr[y][x] == 1) {
                allZero = false;
            }
        }
        if (!allOne && !allZero) break;
    }
    
    Arg arg;
    
    if (allZero == true) {
        arg = { true, true };
    }
    else if (allOne == true) {
        arg = { false, true };
    }
    else {
        arg = { false, false };
    }

    return arg;
}

int oneCnt = 0;
int zeroCnt = 0;

void dq (vector<vector<int>>& arr, int sIdx_x, int sIdx_y, int len) {
    Arg res = checkAllSame(arr, sIdx_x, sIdx_y, len);
    
    if (res.allSame) {
        if (res.isZero) ++zeroCnt;
        else ++oneCnt;
        return;
    }
    
    const int nextLen = len / 2;
    
    dq(arr, sIdx_x          , sIdx_y          , nextLen);        
    dq(arr, sIdx_x + nextLen, sIdx_y          , nextLen);   
    dq(arr, sIdx_x          , sIdx_y + nextLen, nextLen);
    dq(arr, sIdx_x + nextLen, sIdx_y + nextLen, nextLen);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int squareLen = arr.size();
    
    dq(arr, 0, 0, squareLen);
    
    answer.push_back(zeroCnt);
    answer.push_back(oneCnt);
    
    return answer;
}