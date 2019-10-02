/*
==============================+===============================================================
@ File Name : 10809.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_10809_H
#define ALGORITHM_10809_H

#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

void solve(){
   string input;
   cin >> input;

   int alphabets[26];

   memset(alphabets, -1, sizeof(alphabets));

   int count = 0;
   for_each(input.begin(), input.end(),
           [count, &alphabets] (const char ch) mutable ->
           void { if (alphabets[ch-0x61] == -1) { alphabets[ch-0x61] = count; } ++count; });

   for_each(alphabets, alphabets + 26, [](int x)-> void { cout << x << " "; });

}
#endif //ALGORITHM_10809_H
