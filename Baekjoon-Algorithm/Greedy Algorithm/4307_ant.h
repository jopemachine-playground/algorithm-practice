#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

/*
https://dojang.io/mod/page/view.php?id=638 - �� ���� ����
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int testCaseNumber;
int antNumber;
int rodLength;
int* antStartPosition;
int* antFallTime;
string resultStr = "";

int compare(const void* a, const void* b)    
{
	int num1 = *(int*)a;   
	int num2 = *(int*)b;    

	if (num1 > num2)    
		return -1;      

	if (num1 < num2)   
		return 1;       

	return 0;   
}

void solve_4307() {

	scanf("%d", &testCaseNumber);

	for (int j = 0; j < testCaseNumber; j++) {

		scanf("%d %d", &rodLength, &antNumber);

		antStartPosition = new int[antNumber];
		antFallTime = new int[antNumber];

		for (int i = 0; i < antNumber; i++) {
			scanf("%d", &antStartPosition[i]);
		}

		for (int i = 0; i < antNumber; i++) {
			if (antStartPosition[i] < (float) rodLength / 2) {
				antFallTime[i] = antStartPosition[i];
			}
			else {
				antFallTime[i] = rodLength - antStartPosition[i];
			}
		}

		// quick sort
		qsort(antFallTime, antNumber, sizeof(int), compare);

		// #Min, #Max
		resultStr += std::to_string(antFallTime[0]) + " " + std::to_string(rodLength - antFallTime[antNumber - 1]) + "\n";

	}

	std::cout << resultStr;

}