#pragma once
#include "./matrix.hpp"

class GaussJordan {
  int _rank;
  Matrix<double> D;

  bool isZero(double v) { return abs(v) < 1e-10; }

 public:
  GaussJordan(const Matrix<double>& A, bool extended = false) : D(A), _rank(0) {
    int H = D.height(), W = D.width();
    for (int col = 0; col < W; ++col) {
      if (extended && col == W - 1) break;
      int pivot = -1;
      for (int row = _rank; row < H; ++row) {
        if (!isZero(D[row][col])) {
          pivot = row;
          break;
        }
      }
      if (pivot == -1) continue;
      swap(D[pivot], D[_rank]);

      for (int col2 = W - 1; col2 >= col; --col2)
        D[_rank][col2] /= D[_rank][col];

      for (int row = 0; row < H; ++row) {
        if (row != _rank && !isZero(D[row][col])) {
          auto r = D[row][col];
          for (int col2 = 0; col2 < W; ++col2) {
            D[row][col2] -= D[_rank][col2] * r;
          }
        }
      }
      ++_rank;
    }
  }

  inline const auto& operator[](int row) const { return D[row]; }
  int rank() { return _rank; }
};