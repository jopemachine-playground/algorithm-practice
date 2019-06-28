#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 브루트 포스로 풀기
void solve_1966() {

	queue<int> que;
	int testNumber;
	cin >> testNumber;
	int** impArray = new int* [testNumber];
	int* result = new int[testNumber];
	memset(result, 0, sizeof(int) * testNumber);

	for (int i = 0; i < testNumber; i++) {

		while (!que.empty()) {
			que.pop();
		}

		int loopNumber = 0;
		int targetNumber;
		int docNumber;

		cin >> docNumber >> targetNumber;
		impArray[i] = new int[docNumber];

		memset(impArray[i], 0, sizeof(int) * docNumber);

		// 우선순위 배열 셋팅, 큐를 만듬
		for (int j = docNumber - 1; j >= 0; j--) {
			cin >> impArray[i][j];
			que.push(impArray[i][j]);
		}

		// j번째 배열의 우선순위 값을 확인하고 최대 값이 아니라면, 
		// 인쇄하지 않고 큐의 마지막으로 보낸다
		// 위 과정을 반복해 우선순위가 높은 문서 순으로 출력한다
		while(!que.empty()) {

			bool isMax = true;

			// impArray[i][que.size() - 1] (큐의 front에 해당하는 원소) 가 최대값인지 확인
			for (int k = 0; k < que.size(); k++) {
				if (impArray[i][que.size() - 1] < impArray[i][k]) {
					isMax = false;
					break;
				}
			}
			
			// 최대값이라면 제거하거나, targetNumber일 경우 답을 내리고 중단
			if (isMax) {

				que.pop();

				if (targetNumber == 0) {
					result[i] = ++loopNumber;
					break;
				}
				else {
					targetNumber--;
					loopNumber++;
				}
		
			}
			
			// 최댓값이 아니라면 큐의 rear에 다시 삽입하고 반복.
			// 아래 케이스에선 인쇄가 일어나지 않으므로 loopNumber가 증가하지 않음
			else {
				int temp = que.front();
				que.push(que.front());
				que.pop();
				
				// 배열을 한 칸 씩 앞으로 땡기고, 마지막 값에 temp를 대입
				for (int k = que.size() - 1; k > 0; k--) {
					impArray[i][k] = impArray[i][k - 1];
				}

 				impArray[i][0] = temp;
				
				if (targetNumber == 0) {
					targetNumber = que.size() - 1;
				}
				else {
					targetNumber--;
				}
			}
		}
	}

	for (int i = 0; i < testNumber; i++)
		cout << result[i] << "\n";
	
}