#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> d;

int main() {
  cin >> N >> K;
  d.resize(N);

  rep(i, N) {
    char c;
    cin >> c;
    d[i] = (c == 'L' ? 0 : 1);
  }

  int score = 0;
  rep(i, N - 1) {
    if (d[i + 1] == d[i]) ++score;
  }

  cout << min(score + 2 * K, N - 1) << endl;
  return 0;
}
