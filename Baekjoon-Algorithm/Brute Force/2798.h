#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int descendingCompare(const void* a, const void* b)
{
    int num1 = *(int*) a;
    int num2 = *(int*) b;

    if (num1 > num2)
        return -1;
    else if (num1 < num2)
        return 1;
    else return 0;
}

void solve(){
    int N, M;
    cin >> N >> M;

    int inputs[N];
    for (int i = 0; i < N; i++)
        cin >> inputs[i];

    int result = INT64_MIN;
//    for_each(inputs, inputs + N,
//            [=, &inputs, &result](int x1) -> void { for_each(inputs, inputs + N,
//                    [=, &inputs, &result](int x2)-> void { for_each(inputs, inputs + N,
//                            [=, &inputs, &result](int x3) -> void {
//                                int sum = x1 + x2 + x3;
//                                if(sum <= M && M - result > M - sum){
//                                    result = sum;
//                                }
//                            });});});

    qsort(inputs, N, sizeof(int), descendingCompare);

    for(int i = 0; i < N - 2; i++){
        for(int j = i + 1; j < N - 1; j++){
            for(int k = j + 1; k < N; k++){
                int sum = inputs[i] + inputs[j] + inputs[k];
                if(sum <= M && M - result > M - sum){
                    result = sum;
                }
            }
        }
    }


    cout << result;

}