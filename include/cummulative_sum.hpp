template <typename T>
class CummulativeSum {
  vector<T> S;

 public:
  CummulativeSum(const vector<T>& a) {
    int n = a.size();
    S.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      S[i + 1] = S[i] + a[i];
    }
  }

  // [i, j)
  T query(int i, int j) { return S[j] - S[i]; }
};
