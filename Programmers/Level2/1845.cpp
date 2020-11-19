#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> set;
    
    for (int i = 0; i < nums.size() && set.size() < (nums.size() / 2); ++i) {
        auto iter = set.find(nums[i]);
        if (iter == set.end()) {
            set.insert(nums[i]);
        }
    }

    return set.size();
}