// 백준 알고리즘 강의 중급
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 배울 수 있는 단어의 갯수를 체크
int count (int mask, vector<int>& words) {
  int cnt = 0;
  for (int word : words) {
    // 전체 알파벳 중 word에 있는 알파벳을 모두 뺀다.
    // => word에 없는 알파벳 이 mask에 존재하지 않는 경우 해당 알파벳을 배울 수 있다
    if ((word & (((1 << 26) - 1) - mask)) == 0) {
      cnt++;
    }
  }
  return cnt;
}

// mask는 배운 알파벳의 비트 마스크 패턴
int go (int index, int k, int mask, vector<int>& words) {
  if (k < 0) return 0;
  if (index == 26) return count(mask, words);
  int ans = 0;

  // 새 알파벳을 배우는 경우
  int t1 = go(index + 1, k - 1, mask | (1 << index), words);
  if (ans < t1) ans = t1;

  // a, n, t, i, c는 항상 배워야 하므로 가지치기로 제외.
  // 나머지 알파벳들은 배울 수도 배우지 않을 수도 있음.
  if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
    t1 = go(index + 1, k, mask, words);
    if (ans < t1) ans = t1;
  }

  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> words;

  for (int i = 0; i < N; ++i) {
    int wordPattern = 0;
    string word;
    cin >> word;
    for (char ch : word) {
      wordPattern |= (1 << (ch - 'a'));
    }

    words.push_back(wordPattern);
  }

  cout << go(0, M, 0, words) << '\n';
  return 0;
}