#include <string>
#include <vector>

using namespace std;

int fibonacci(int k) {
    static int cache [100000] = { 0, 1, 1,};

    int first = (k >= 1 && cache[k - 1] != 0) ? cache[k - 1] : fibonacci(k - 1);
    int second = (k >= 2 && cache[k - 2] != 0) ? cache[k - 2] : fibonacci(k - 2);
    
    cache[k] = (first + second) % 1234567;
    return (first + second) % 1234567;
}

int solution(int n) {
    int answer = fibonacci(n);
    return answer;
}