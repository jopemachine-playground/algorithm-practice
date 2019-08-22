/*
==============================+===============================================================
@ File Name : 11399_atm.h
@ Author : jopemachine
@ Created Date : 2019-06-28, 18:39:12
@ Desc : 
@    ATM
==============================+===============================================================
*/
#pragma once
// to use unsafe function
#pragma warning(disable: 4996)
/*
http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220790825104&parentCategoryNo=&categoryNo=14&viewDate=&isShowPopularPosts=false&from=postView
*/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void solve_11399() {
	// Prev Condition :: 1 <= personNumber <= 1000
	string personStr;
	getline(cin, personStr);
	// string to int
	const int personNumber = atoi(personStr.c_str());

	// Prev Condition :: 1 <= personWaitingTime <= 1000
	string personWaitingTimeStr; 

	// string to char[]
	getline(cin, personWaitingTimeStr);
	char *cstr = new char[personNumber];
	strcpy(cstr, personWaitingTimeStr.c_str());

	const char* waitingTimeChars = strtok(cstr, " ");
	int* waitingTimes = NULL;
	waitingTimes = new int[personNumber] {};

	for (int i = 0; waitingTimeChars != NULL; i++) {
		// char to int
		*(waitingTimes + i) = atoi(waitingTimeChars);
		waitingTimeChars = strtok(NULL, " ");
	}

	// bubble sort
	for (int i = personNumber - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (waitingTimes[j] < waitingTimes[j + 1]) {
				int temp = waitingTimes[j];
				waitingTimes[j] = waitingTimes[j + 1];
				waitingTimes[j + 1] = temp;
			}
		}
	}

	int sum = 0;
	// sum
	for (int i = personNumber - 1; i >= 0; i--) {
		sum += waitingTimes[i] * (i+1);
	}

	printf("%d\n", sum);
}

void solve_11399_2() {
	int personNumber;

	// Prev Condition :: 1 <= personNumber <= 1000
	int waitingTimes[1001];

	scanf("%d", &personNumber);

	for (int i = 1; i <= personNumber; i++) {
		scanf("%d", &waitingTimes[i]);
	}

	// bubble sort
	for (int i = personNumber; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (waitingTimes[j] < waitingTimes[j + 1]) {
				int temp = waitingTimes[j];
				waitingTimes[j] = waitingTimes[j + 1];
				waitingTimes[j + 1] = temp;
			}
		}
	}

	int sum = 0;
	// sum
	for (int i = personNumber - 1; i >= 0; i--) {
		sum += waitingTimes[i] * (i + 1);
	}

	printf("%d\n", sum);


}