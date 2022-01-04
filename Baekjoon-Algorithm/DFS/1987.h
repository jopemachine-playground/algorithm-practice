/*
==============================+===============================================================
@ File Name : 1987_Alphabet.h
@ Author : jopemachine
@ Desc : 
@    알파벳
@    DFS 문제.
@    Ref: 백준 중급 강의
==============================+===============================================================
*/
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int go(vector<string>& board, vector<bool>& check, int x, int y) {
  int ans = 0;
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
      // 방문한 적 있으면 idx에 올바른 값이 들어감.
      auto idx = board[nx][ny] - 'A';
      if (check[idx] == false) {
        check[idx] = true;
        int next = go(board, check, nx, ny);
        if (ans < next) ans = next;
        check[idx] = false;
      }
    }
  }
  return ans + 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> board(n);

  for (int i=0; i<n; i++) {
    cin >> board[i];
  }
  vector<bool> check(26);
  check[board[0][0]-'A'] = true;
  cout << go(board, check, 0, 0) << '\n';

  return 0;
}