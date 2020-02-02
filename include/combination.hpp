/**
 * @brief O(n)の事前計算で、組み合わせ関係の値をO(1)で出せるようにする
 * @tparam T
 */
template <typename T>
class Combination {
  vector<T> fact, ifact;

 public:
  /**
   * @brief [0,n]までの階乗、その逆元をO(n)で事前計算
   * @param nMax
   */
  Combination(int nMax) : fact(nMax + 1), ifact(nMax + 1) {
    fact[0] = 1;
    for (int i = 0; i < nMax; ++i) fact[i + 1] = fact[i] * (i + 1);
    for (int i = 0; i < nMax + 1; ++i) ifact[i] = fact[i].inverse();
  }

  T factorial(int n) const { return fact[n]; }
  T inverseFactorial(int n) const { return ifact[n]; }

  T P(int n, int k) const {
    if (n < 0 || k < 0 || n < k) return 0;
    return factorial(n) * inverseFactorial(n - k);
  }

  T C(int n, int k) const {
    if (n < 0 || k < 0 || n < k) return 0;
    return factorial(n) * inverseFactorial(n - k) * inverseFactorial(k);
  }

  T H(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : C(n + k - 1, k);
  }
};
