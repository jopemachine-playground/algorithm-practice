#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// ���Ʈ ������ Ǯ��
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

		// �켱���� �迭 ����, ť�� ����
		for (int j = docNumber - 1; j >= 0; j--) {
			cin >> impArray[i][j];
			que.push(impArray[i][j]);
		}

		// j��° �迭�� �켱���� ���� Ȯ���ϰ� �ִ� ���� �ƴ϶��, 
		// �μ����� �ʰ� ť�� ���������� ������
		// �� ������ �ݺ��� �켱������ ���� ���� ������ ����Ѵ�
		while(!que.empty()) {

			bool isMax = true;

			// impArray[i][que.size() - 1] (ť�� front�� �ش��ϴ� ����) �� �ִ밪���� Ȯ��
			for (int k = 0; k < que.size(); k++) {
				if (impArray[i][que.size() - 1] < impArray[i][k]) {
					isMax = false;
					break;
				}
			}
			
			// �ִ밪�̶�� �����ϰų�, targetNumber�� ��� ���� ������ �ߴ�
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
			
			// �ִ��� �ƴ϶�� ť�� rear�� �ٽ� �����ϰ� �ݺ�.
			// �Ʒ� ���̽����� �μⰡ �Ͼ�� �����Ƿ� loopNumber�� �������� ����
			else {
				int temp = que.front();
				que.push(que.front());
				que.pop();
				
				// �迭�� �� ĭ �� ������ �����, ������ ���� temp�� ����
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