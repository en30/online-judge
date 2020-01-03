#include <bits/stdc++.h>
#include "../include/template"
#include "../include/matrix.hpp"

struct Num {
  unsigned int val;
  Num(int v) : val(v) {}

  static Num identity() { return Num(numeric_limits<unsigned int>::max()); }

  Num& operator+=(const Num& n) {
    val ^= n.val;
    return *this;
  }
  Num operator+(const Num& n) const { return Num(*this) += n; }
  Num operator*(const Num& n) const { return Num(val & n.val); }

  friend ostream& operator<<(ostream& os, Num& n) { return os << n.val; }
  friend istream& operator>>(istream& is, Num& n) { return is >> n.val; }
};

int K, M;

Matrix<Num> power(const Matrix<Num>& A, int r) {
  int n = A.height(), m = A.width();

  Matrix<Num> C(A);
  Matrix<Num> R(n, m, 0);
  rep(i, n) R[i][i] = Num::identity();

  while (r > 0) {
    if (r & 1) R *= C;
    C *= C;
    r >>= 1;
  }
  return R;
}

int main() {
  cin >> K >> M;
  Matrix<Num> T(K, K, 0), v(K, 1);
  rep(i, K) cin >> v[K - 1 - i][0];
  rep(i, K) cin >> T[0][i];
  rep(i, K - 1) T[i + 1][i] = Num::identity();

  if (M <= K) {
    cout << v[K - M][0] << endl;
    return 0;
  }

  v = power(T, M - K) * v;

  cout << v[0][0] << endl;

  return 0;
}
