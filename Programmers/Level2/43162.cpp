#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class DisjointSet {
public:
    vector<int> parents;
    
    DisjointSet(int n) {
        parents = vector<int>(n);
        for (int i = 0; i < n; ++i)
            parents[i] = i;
    }
    
    int find(int u) {
        if (parents[u] == u) return u;
        else return find(parents[u]);
    }
    
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u != v) parents[u] = v;
    }
};
    
int solution(int n, vector<vector<int>> computers) {
    unordered_set<int> set;
    auto unionSet = DisjointSet(n);
    
    for (int i = 0; i < n; ++i) {
        computers[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            if (computers[i][j] == 1) {
                unionSet.merge(i, j);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        set.insert(unionSet.find(i));
    }
            
    return set.size();
}