#ifndef ALGORITHM_1546_H
#define ALGORITHM_1546_H

#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

void solve(){
   int N;
   cin >> N;

   int input[N];
   for (int i = 0; i < N; i++){
       cin >> input[i];
   }

   double M = *max_element(input, input + N);

   double inputD[N];

   transform(input, input + sizeof(input) / sizeof(int), inputD, [M](double x)-> double { return (x / M) * 100;});

   double sum = (double) accumulate(inputD, inputD + sizeof(inputD) / sizeof(double), 0.0);

   cout << sum / N;

}
#endif //ALGORITHM_1546_H
