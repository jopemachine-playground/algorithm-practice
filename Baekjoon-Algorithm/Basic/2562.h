/*
==============================+===============================================================
@ File Name : 2562.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_2562_H
#define ALGORITHM_2562_H

#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

void solve_2562(){
   int A[9];
   int max = INT_MIN;
   int maxIndex = -1;

   for (int i = 0; i < 9; i++){
       cin >> A[i];
       if(max < A[i]) {
           max = A[i];
           maxIndex = i + 1;
       }
   }

   cout << max << "\n";
   cout << maxIndex;
}

#endif //ALGORITHM_2562_H
