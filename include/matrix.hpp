template <typename T>
class Matrix {
  vector<vector<T>> A;

 public:
  Matrix(size_t n, size_t m, T v = 0) : A(n, vector<T>(m, v)){};

  size_t height() const { return A.size(); }

  size_t width() const { return A[0].size(); }

  inline const vector<T> &operator[](int k) const { return A[k]; }
  inline vector<T> &operator[](int k) { return A[k]; }

  static Matrix I(size_t n) {
    Matrix m(n, n, 0);
    for (int i = 0; i < n; ++i) m[i][i] = 1;
    return m;
  }

  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        (*this)[i][j] += B[i][j];
      }
    }
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), l = width(), m = B.width();
    assert(l == B.height());
    vector<vector<T>> C(n, vector<T>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < l; ++k) {
          C[i][j] += (*this)[i][k] * B[k][j];
        }
      }
    }
    A.swap(C);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix power(long long r) const {
    assert(height() == width());
    Matrix A(*this), B(Matrix::I(height()));
    while (r > 0) {
      if (r & 1) B *= A;
      A *= A;
      r >>= 1;
    }
    return B;
  }

  friend ostream &operator<<(ostream &os, const Matrix &A) {
    size_t n = A.height(), m = A.width();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j != 0) os << " ";
        os << A[i][j];
      }
      os << endl;
    }
    return os;
  }

  friend istream &operator>>(istream &is, Matrix &A) {
    size_t n = A.height(), m = A.width();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        is >> A[i][j];
      }
    }
    return is;
  }
};
