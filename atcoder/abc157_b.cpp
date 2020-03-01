#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  int N;
  cin >> N;
  rep(i, N) {
    int b;
    cin >> b;
    rep(i, 3) rep(j, 3) if (A[i][j] == b) A[i][j] = -1;
  }

  rep(i, 3) {
    int r = 0, c = 0;
    rep(j, 3) {
      r += A[i][j];
      c += A[j][i];
    }
    if (r == -3 || c == -3) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  int a = 0, b = 0;
  rep(i, 3) {
    a += A[i][i];
    b += A[2 - i][i];
  }
  if (a == -3 || b == -3) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}
