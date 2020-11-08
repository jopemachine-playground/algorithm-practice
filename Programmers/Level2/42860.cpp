#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    
    vector<int> costs;
    int lcost = -1;
    int rcost = -1;
    string currentName = basic_string(name.size(), 'A');
    if (name == currentName) return 0;
    
    // calc right
    int i = 0;
    while (currentName != name) {
        char ch = name.at(i);
        // turn left and caculate the cost
        if (ch == 'A') {
            int cost = rcost + i - 1;
            int j = 0;
            string currentNameWithTL = currentName;
            while (currentNameWithTL != name) {
                int idx = name.size() - 1 - j;
                char ch = name.at(idx);
                int chDiff = (ch - 'A' < 'Z' - ch + 1) ? ch - 'A' : 'Z' - ch + 1;
                cost += chDiff;
                ++cost;
                currentNameWithTL[idx] = ch;
                ++j;
            }
            costs.push_back(cost);
        }
        // 0 ~ 25
        int chDiff = (ch - 'A' < 'Z' - ch + 1) ? ch - 'A' : 'Z' - ch + 1;
        rcost += chDiff;
        ++rcost;
        currentName[i] = ch;
        ++i;
    }

    costs.push_back(rcost);
    currentName = basic_string(name.size(), 'A');
    
    // calc left
    i = 0;
    while (currentName != name) {
        int idx = i == 0 ? 0 : name.size() - i;
        char ch = name.at(idx);
        // 0 ~ 25
        int chDiff = (ch - 'A' < 'Z' - ch + 1) ? ch - 'A' : 'Z' - ch + 1;
        lcost += chDiff;
        ++lcost;
        currentName[idx] = ch;
        ++i;
    }

    costs.push_back(lcost);

    int minCost = *min_element(costs.begin(), costs.end());
    
    return minCost;
}