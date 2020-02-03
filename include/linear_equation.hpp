#pragma once
#include "./matrix.hpp"
#include "./gauss_jordan.hpp"
template <typename T>
class LinearEquation {
  vector<T> _ans;
  bool _solvable;

 public:
  LinearEquation(Matrix<T> A, vector<T> b) {
    int m = A.height(), n = A.width();
    Matrix<T> M(m, n + 1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
      M[i][n] = b[i];
    }

    GaussJordan C(M, true);

    _solvable = true;
    for (int row = C.rank(); row < m; ++row) {
      if (C[row][n]) _solvable = false;
    }

    _ans.resize(n, 0);
    for (int i = 0; i < C.rank(); ++i) _ans[i] = C[i][n];
  }

  bool solvable() { return _solvable; }

  T operator[](int i) const { return _ans[i]; }
};