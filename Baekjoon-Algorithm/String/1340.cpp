/*
==============================+===============================================================
@ Title : 연도 진행바
@ Desc :
@ Ref :
==============================+===============================================================
*/

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <array>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define debug if constexpr (LOCAL) cout
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

string months[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

int findMonthIdx(string str) {
  for (int i = 0; i < 12; ++i) {
    if (months[i] == str) return i;
  }
  return -1;
}

int days[] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool isLeapYear(int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int solve() {
  _FASTIOS;
  string month, day, year, hourMin;
  cin >> month >> day >> year >> hourMin;

  int yearAmount = stoi(year);
  int monthIdx = findMonthIdx(month);
  int dayAmount = stoi(day.substr(0, day.length() - 1));
  int hour = stoi(hourMin.substr(0, 2));
  int min = stoi(hourMin.substr(3, 5));

  if (isLeapYear(yearAmount)) {
    days[1] = 29;
  }

  int dayTotal = 0;

  // 12월 동안 며칠 있는지
  for (int i = 0; i < 12; ++i) {
    dayTotal += days[i];
  }

  int secondsPerDay = 3600 * 24;

  int yearSeconds = dayTotal * secondsPerDay;

  // 현재
  dayTotal = (dayAmount - 1);
  for (int i = 0; i < monthIdx; ++i) {
    dayTotal += days[i];
  }

  int currentTotalSeconds = dayTotal * secondsPerDay;
  currentTotalSeconds += 3600 * hour + 60 * min;

  cout.precision(10);
  cout << ((double) currentTotalSeconds / yearSeconds) * 100 << "\n";

  return 0;
}