#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> a, win;
int main() {
  cin >> N >> K;
  a.resize(N), win.resize(K + 1, 0);
  rep(i, N) cin >> a[i];

  win[0] = false;

  for (int k = 1; k <= K; ++k) {
    win[k] = false;
    for (int i = 0; i < N && k - a[i] >= 0; ++i) {
      win[k] = win[k] || !win[k - a[i]];
    }
  }

  cout << (win[K] ? "First" : "Second") << endl;

  return 0;
}
