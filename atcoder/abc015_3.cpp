#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<vector<int>> T;

bool buggy(int i, int curr) {
  if (i == N) return curr == 0;

  rep(j, K) if (buggy(i + 1, curr ^ T[i][j])) return true;
  return false;
}

int main() {
  cin >> N >> K;
  T.resize(N, vector<int>(K));
  rep(i, N) rep(j, K) cin >> T[i][j];

  cout << (buggy(0, 0) ? "Found" : "Nothing") << endl;

  return 0;
}
