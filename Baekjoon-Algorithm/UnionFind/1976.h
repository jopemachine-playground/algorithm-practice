
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int find(vector<int>& unionFind, int u) {
    if (unionFind[u] == u) return u;
    return unionFind[u] = find(unionFind, unionFind[u]);
}

void merge(vector<int>& unionFind, int u, int v) {
    u = find(unionFind, u);
    v = find(unionFind, v);
    
    if (u != v) unionFind[u] = v;
}

void solve() {
    int n, m, t;
    cin >> n;
    cin >> m;
    vector<int> unionFind = vector<int>(n + 1);

    for (int i = 1; i <= n; ++i) {
        unionFind[i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            if (t == 1) {
                merge(unionFind, i , j);
            }
        }
    }

    int plan, dest;
    cin >> plan;
    dest = find(unionFind, plan);
    for (int i = 1; i < m; ++i) {
        cin >> plan;
        if (dest != find(unionFind, plan)) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}
