#include <iostream>
#include <queue>

using namespace std;

int     map[1001][1001];
int    dist[1001][1001][2];
queue<pair<pair<int, int>, int>> que;

void solve(){
    int N, M;
    cin >> N >> M;

    string oneline = "";

    for (int i = 1; i <= N; i++){
        cin >> oneline;
        for (int j = 1; j <= M; j++){
            map[i][j] = oneline[j - 1] - '0';
        }
    }

    que.push({{1, 1}, 0});
    dist[1][1][0] = 1;

    while(!que.empty()) {

        int x = que.front().first.first;
        int y = que.front().first.second;

        int crashCnt = que.front().second;

        int presentDist = dist[y][x][1] == 0 ? dist[y][x][0] : dist[y][x][1];

        // left
        if(x - 1 >= 1){
            if(map[y][x - 1] == 0 && dist[y][x - 1][0] == 0){
                dist[y][x - 1][crashCnt] = presentDist + 1;
                que.push({{x - 1, y}, crashCnt});
            }
            if(map[y][x - 1] == 1 && dist[y][x - 1][1] == 0 && crashCnt == 0){
                dist[y][x - 1][1] = presentDist + 1;
                que.push({{x - 1, y}, crashCnt + 1});
            }
        }

        // right
        if(x + 1 <= M){
            if(map[y][x + 1] == 0 && dist[y][x + 1][0] == 0){
                dist[y][x + 1][crashCnt] = presentDist + 1;
                que.push({{x + 1, y}, crashCnt});
            }
            if(map[y][x + 1] == 1 && dist[y][x + 1][1] == 0 && crashCnt == 0){
                dist[y][x + 1][1] = presentDist + 1;
                que.push({{x + 1, y}, crashCnt + 1});
            }
        }

        // up
        if(y - 1 >= 1){
            if(map[y - 1][x] == 0 && dist[y - 1][x][0] == 0){
                dist[y - 1][x][crashCnt] = presentDist + 1;
                que.push({{x, y - 1}, crashCnt});
            }
            if(map[y - 1][x] == 1 && dist[y - 1][x][1] == 0 && crashCnt == 0){
                dist[y - 1][x][1] = presentDist + 1;
                que.push({{x, y - 1}, crashCnt + 1});
            }
        }

        // down
        if(y + 1 <= N){
            if(map[y + 1][x] == 0 && dist[y + 1][x][0] == 0){
                dist[y + 1][x][crashCnt] = presentDist + 1;
                que.push({{x, y + 1}, crashCnt});
            }
            if(map[y + 1][x] == 1 && dist[y + 1][x][1] == 0 && crashCnt == 0){
                dist[y + 1][x][1] = presentDist + 1;
                que.push({{x, y + 1}, crashCnt + 1});
            }
        }

        que.pop();
    }

    if(dist[N][M][1] == 0 && dist[N][M][0] != 0)
        cout << dist[N][M][0];
    else if(dist[N][M][0] == 0 && dist[N][M][1] != 0)
        cout << dist[N][M][1];
    else cout << -1;

//    for (int i = 1; i <= N; i++){
//        for(int j = 1; j <= M; j++){
//            cout << dist[i][j][0] << " ";
//        }
//        cout << "\n";
//    }
//
//    cout << "\n";
//
//    for (int i = 1; i <= N; i++){
//        for(int j = 1; j <= M; j++){
//            cout << dist[i][j][1] << " ";
//        }
//        cout << "\n";
//    }

}
