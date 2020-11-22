#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> answer;

long long find(unordered_map<long long, long long>& parents, long long u) {
    // 없으면 0, base case.
    if (parents[u] == 0) {
        parents[u] = u + 1;
        answer.push_back(u);
        return u;
    }
    return parents[u] = find(parents, parents[u]);
}
    
vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> parents;

    // +1 해서 쓸 것이므로 1개 올리고, 20만개까지 가능하므로 1개 올려 200002개 필요
    parents.reserve(200002);

    for (int i = 0; i < room_number.size(); ++i) {
        long long n = room_number[i];
        if (parents[n] == 0) {
            answer.push_back(n);
            parents[n] = n + 1;
        }
        else {
            find(parents, n);
        }
    }
    return answer;
}