#include <bits/stdc++.h>
#include "../include/template"
#include "../include/linear_equation.hpp"

int main() {
  Matrix<double> A(2, 2);
  vector<double> b(2);

  while (true) {
    rep(i, 2) {
      rep(j, 2) cin >> A[i][j];
      cin >> b[i];
    }
    if (cin.eof()) break;
    LinearEquation<double> le(A, b);
    printf("%.3lf %.3lf\n", le[0], le[1]);
  }

  return 0;
}
