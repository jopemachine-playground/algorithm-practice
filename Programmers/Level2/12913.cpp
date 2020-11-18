#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int dp[100000][4];

    // Base case
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            int max = -1;
            for (int k = 0; k < 4; ++k) {
                if (j == k) continue;
                if (dp[i - 1][k] > max) max = dp[i - 1][k];
            }
            dp[i][j] = max + land[i][j];
        }
    }
    
    return *max_element(dp[land.size() - 1], dp[land.size() - 1] + 4);
}