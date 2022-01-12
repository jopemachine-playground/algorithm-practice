#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void solve(){
	vector<int> answer;

	vector<string> maps = {"..........","AAACC.....",".AAA.....Z","..AAAA..C.","...BBBBB..","....BBB...","...ZBBB...","ZZZZAAAC..",".....CCCC.","QQ......C.",".........."};

	// 세로 길이
	int M = maps.size();
	// 가로 길이
	int N = maps[0].length();

	char map[M][N];
	int  visited[M][N];

	for (int i = 0; i < M; i++) {
		memset(map[i], -1, sizeof(char) * M);
		memset(visited[i], -1, sizeof(int) * M);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			string oneline = maps[i];
			map[i][j] = oneline.at(j);
		}
	}

    queue<pair<int, int>> que;

    vector<pair<char, char>> visitLog;

    // 시작점 push
    for (int i = 0; i < M; i++){

        // visited 초기화
        for (int i = 0; i < M; i++) {
            memset(visited[i], -1, sizeof(int) * M);
        }

        for(int j = 0; j < N; j++){

            if(map[i][j] == '.') continue;

            que.push({j, i});

            while(!que.empty()){

                int x = que.front().first;
                int y = que.front().second;

                // 오른쪽으로 이동
                if(x + 1 < N && map[y][x + 1] != '.' && visited[y][x + 1] == -1){
                    // 방문한 적 없는 국경을 방문, 같은 나라일 경우 노 카운트
                    if((map[y][x + 1] != map[y][x]) && std::find(visitLog.begin(), visitLog.end(), make_pair(map[y][x+1], map[y][x])) == visitLog.end()){
                        visitLog.push_back({ map[y][x + 1], map[y][x] });
                    }

                    visited[y][x + 1] = 1;
                    que.push({x + 1, y});
                }

                // 왼쪽으로 이동
                if(x - 1 >= 0 && map[y][x - 1] != '.' && visited[y][x - 1] == -1){
                    // 방문한 적 없는 국경을 방문, 같은 나라일 경우 노 카운트
                    if((map[y][x - 1] != map[y][x]) && find(visitLog.begin(), visitLog.end(), make_pair(map[y][x - 1], map[y][x])) == visitLog.end()){
                        visitLog.push_back({ map[y][x - 1], map[y][x] });
                    }
                    visited[y][x - 1] = 1;
                    que.push({x - 1, y});
                }

                // 위로 이동
                if(y + 1 < M && map[y + 1][x] != '.' && visited[y + 1][x] == -1){
                    // 방문한 적 없는 국경을 방문, 같은 나라일 경우 노 카운트
                    if((map[y + 1][x] != map[y][x]) && find(visitLog.begin(), visitLog.end(), make_pair(map[y+1][x], map[y][x])) == visitLog.end()){
                        visitLog.push_back({ map[y + 1][x], map[y][x] });
                    }
                    visited[y + 1][x] = 1;
                    que.push({x, y + 1});
                }
                // 아래로 이동
                if(y - 1 >= 0 && map[y - 1][x] != '.' && visited[y - 1][x] == -1){
                    // 방문한 적 없는 국경을 방문, 같은 나라일 경우 노 카운트
                    if((map[y - 1][x] != map[y][x])&& find(visitLog.begin(), visitLog.end(), make_pair(map[y-1][x], map[y][x])) == visitLog.end()){
                        visitLog.push_back({ map[y - 1][x], map[y][x] });
                    }
                    visited[y - 1][x] = 1;
                    que.push({x, y - 1});
                }

                que.pop();

            }
        }
    }

//    sharingBoundsCnt = (visitLog.size() / 2);

    int tmp[26];
    memset (tmp, 0, sizeof(int) * 26);

    for(int i = 0; i < visitLog.size(); i++){
        // cout << visitLog[i].first << " " << visitLog[i].second << "\n";
        tmp[visitLog[i].first - 65]++;
    }

    cout << *max_element(tmp, tmp + 26);

}
