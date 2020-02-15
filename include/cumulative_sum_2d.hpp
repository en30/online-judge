#pragma once

template <typename T>
class CumulativeSum2D {
  vector<vector<T>> S;

 public:
  CumulativeSum2D(const vector<vector<T>>& a) {
    int n = a.size(), m = a[0].size();
    S.resize(n + 1, vector<T>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j] + a[i][j];
      }
    }
  }

  // [i1, i2) x (j1, j2)
  T query(int i1, int j1, int i2, int j2) {
    return S[i2][j2] - S[i2][j1] - S[i1][j2] + S[i1][j1];
  }
};
