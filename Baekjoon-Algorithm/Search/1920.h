#include <iostream>

using namespace std;

bool binary_search(int arr[], int arr_start, int arr_end, int target){

    if (arr_end < arr_start) return false;

    long t = arr_end + arr_start;

    int middle_index = (int) (t / 2);

    int middle = arr[middle_index];

    if (target == middle) return true;

    if (target > middle) {
        return binary_search(arr, middle_index + 1, arr_end, target);
    }
    else if (target < middle){
        return binary_search(arr, arr_start, middle_index - 1, target);
    }

}

int ascendingCompare(const void* a, const void* b)
{
    int num1 = *(int*) a;
    int num2 = *(int*) b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else return 0;
}

void solve() {
    int N, M;

    cin >> N;

    int input[N];

    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    cin >> M;

    int arr[M];

    for (int i = 0; i < M; i++) {
        cin >> arr[i];
    }

    qsort(input, N, sizeof(int), ascendingCompare);

    for (int i = 0; i < M; i++) {
        if(binary_search(input, 0, N, arr[i])){
            cout << 1 <<"\n";
        }
        else cout << 0 << "\n";
    }
}
