#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int cache[501];

typedef struct {
    vector<int> linkedPts;
    int timeCost;
} BuildingGraphInfo;

int dfs(
    int pt,
    vector<BuildingGraphInfo>& graph,
    vector<bool>& isVisited
) {
    if (graph[pt].linkedPts.size() < 1) return graph[pt].timeCost;

    int& ret = cache[pt];
    if (ret != 0) return ret;

    for (int nextPt : graph[pt].linkedPts) {
        if (isVisited[nextPt] == true) continue;
        ret = max(ret, dfs(nextPt, graph, isVisited));
    }

    ret += graph[pt].timeCost;
    return ret;
}

void solve(){
    int n;
    vector<BuildingGraphInfo> graph;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int time;
        cin >> time;

        vector<int> vec;
        int t;
        int maxTime = -1;
        cin >> t;
        while (t != -1) {
            vec.push_back(t - 1);
            cin >> t;
        }
        graph.push_back({ vec, time });
    }

    for (int i = 0; i < graph.size(); ++i) {
        vector<bool> isVisited = vector<bool>(n, false);
        cout << dfs(i, graph, isVisited) << endl;
    }
}
