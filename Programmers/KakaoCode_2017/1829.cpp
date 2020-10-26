#include <vector>
#include <unordered_map>
#include <iostream>
#include <utility>

#define DEBUG

using namespace std;

void dfs(
    int cx,
    int cy,
    int color,
    int& area,
    vector<vector<int>>& picture,
    vector<vector<bool>>& visited,
    unordered_map<int, int>& counts
)
{
    int rx[4] = {1, 0, -1, 0};
    int ry[4] = {0, 1, 0, -1};
    
    visited[cy][cx] = true;
    ++area;

    for (int i = 0; i < 4; i++)  {
        if (cx + rx[i] >= picture[0].size() || 
            cy + ry[i] >= picture.size() ||
            cx + rx[i] < 0 || 
            cy + ry[i] < 0)
        {
            continue;
        }
        if (picture[cy + ry[i]][cx + rx[i]] == color && 
            visited[cy + ry[i]][cx + rx[i]] == false) 
        {
            dfs(cx + rx[i], cy + ry[i], color, area, picture, visited, counts);
        }
    }

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    unordered_map<int, int> counts;
    vector<vector<bool>> visited = vector (m, vector<bool>(n, false));

    for (int i = 0; i < visited.size(); i++) {
        for (int j = 0; j < visited[0].size(); j++) {
            int color = picture[i][j];
            if (color != 0 && visited[i][j] == false) {
                int area = 0;
                ++number_of_area;
                dfs(j, i, color, area, picture, visited, counts);

                auto mapIter = counts.find(color);

                if (mapIter != counts.end()) {
                    if (mapIter->second < area) {
                        counts.at(color) = area;
                    }
                }
                else {
                    counts.insert({ color, area });
                }
            }
        }
    }

    for (auto key : counts) {
        if (max_size_of_one_area < key.second) {
            max_size_of_one_area = key.second;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}