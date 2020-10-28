#include <string>
#include <vector>
#include <iostream>

using namespace std;

int floodMod (int integer, int div) {
    return (integer + div) % div;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> TwoDSnailArr = vector<vector<int>>(n);
    
    // initialize each vector
    int sizeIdx = 0;
    for (vector<int>& vec : TwoDSnailArr) {
        // -1 means no visiting
        vec = vector<int>(++sizeIdx, -1);
    }
    
    int d = 0;
    int row = 0;
    int col = 0;
    int x_dir[3] = { 0, 1, -1 };
    int y_dir[3] = { 1, 0, -1 };
    int num = 1;
    int nodeCnt = (n * (n + 1)) / 2;
    int limitedForDebug = 0;
    
    TwoDSnailArr[0][0] = 1;

    while (num < nodeCnt) {
        // move in selected direction  
        int tempRow = row + x_dir[d];
        int tempCol = col + y_dir[d];

        // handle out of array case
        if (
            tempCol <  0 ||
            tempCol >= n ||
            tempRow <  0 ||
            tempRow >= TwoDSnailArr[tempCol].size()) 
        {
            d = floodMod(d + 1, 3);   
        }
        // handle visiting case
        else if (TwoDSnailArr[tempCol][tempRow] != -1) {
            d = floodMod(d + 1, 3);
        }
        // visit
        else {
            row = tempRow;
            col = tempCol;
            TwoDSnailArr[col][row] = ++num;
        }
    }
    
    // make 1D array
    for (int i = 0; i < TwoDSnailArr.size(); i++) {
        for (int j = 0; j < TwoDSnailArr[i].size(); j++) {
            answer.push_back(TwoDSnailArr[i][j]);
        }
    }    

    return answer;
}