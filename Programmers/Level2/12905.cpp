#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int maxLen = 0;

    if (board.size() <= 1 || board[0].size() <= 1) return 1;

    for (int i = 1; i < board.size(); ++i) {
        for (int j = 1; j < board[0].size(); ++j) {
            // If the i, jth value is zero, not need to continue.
            if (board[i][j] == 1) {
                int comp[3] = { board[i - 1][j - 1], board[i - 1][j], board[i][j - 1] };
                int min = *min_element(comp, comp + 3);
                board[i][j] = min + 1;
                if (maxLen < min + 1) maxLen = min + 1;
            }
        }
    }

    return maxLen * maxLen;
}