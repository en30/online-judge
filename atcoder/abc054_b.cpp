#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<vector<int>> A, B;
int main() {
  cin >> N >> M;
  A.resize(N, vector<int>(N, 0));
  B.resize(M, vector<int>(M, 0));
  {
    char c;
    rep(i, N) rep(j, N) {
      cin >> c;
      if (c == '#') A[i][j] = 1;
    }
    rep(i, M) rep(j, M) {
      cin >> c;
      if (c == '#') B[i][j] = 1;
    }
  }

  for (int di = 0; M + di <= N; ++di) {
    for (int dj = 0; M + dj <= N; ++dj) {
      bool match = true;
      rep(i, M) rep(j, M) {
        if (A[i + di][j + dj] != B[i][j]) match = false;
      }
      if (match) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
