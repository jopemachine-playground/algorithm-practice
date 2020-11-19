#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 홀수일 땐 가운데 있는 거 까지 세야함.
    int endNum = (n + 1) / 2;
    int minusNum = 1;
    int sum = 0;
    for (int i = 1; i <= endNum; ++i) {
        sum += i;
        if (sum >= n) {
            while (sum > n) sum -= minusNum++;
            if (sum == n) answer++;
        }
    }
    
    return answer + 1;
}