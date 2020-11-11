#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

typedef int weight_t;
typedef int elapsedTime_t;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int currentWeight = 0;
    
    queue<pair<weight_t, elapsedTime_t>> crossingTrucks;
    queue<weight_t> waitingTrucks;
 
    for (int i = 0; i < truck_weights.size(); ++i) {
        waitingTrucks.push(truck_weights[i]);
    }

    while (!(waitingTrucks.empty() && crossingTrucks.empty())) {
        ++time;

        if (!crossingTrucks.empty())
        {
            auto top = crossingTrucks.front();
            if (time - top.second >= bridge_length)
            {
                currentWeight -= top.first;
                crossingTrucks.pop();
            }
        }

        if (!waitingTrucks.empty())
        {
            if (currentWeight + waitingTrucks.front() <= weight)
            {
                crossingTrucks.push({ waitingTrucks.front(), time });
                currentWeight += waitingTrucks.front();
                waitingTrucks.pop();
            }
        }
    }
    
    return time;
}