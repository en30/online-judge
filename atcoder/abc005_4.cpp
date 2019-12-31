#include <bits/stdc++.h>
#include "../include/template"

int N, Q;
vector<vector<int>> D;

int main() {
  cin >> N;
  D.resize(N, vector<int>(N));
  rep(i, N) rep(j, N) cin >> D[i][j];

  vector<int> T(N * N + 1, 0);
  rep(i, N) rep(j, N) {
    for (int k = i; k < N; ++k) {
      int sum = 0;
      for (int l = j; l < N; ++l) {
        for (int y = i; y <= k; ++y) sum += D[y][l];
        int s = (k - i + 1) * (l - j + 1);
        T[s] = max(T[s], sum);
      }
    }
  }

  cin >> Q;
  rep(i, N * N) T[i + 1] = max(T[i], T[i + 1]);

  rep(i, Q) {
    int P;
    cin >> P;
    cout << T[P] << endl;
  }

  return 0;
}
