#pragma once
#include "./mod.hpp"
#include "./combination.hpp"

class StirlingNumber {
  vector<vector<ModInt>> res;

 public:
  /**
   * @brief スターリング数を計算する O(K log N)
   * @param N
   * @param K
   * @return
   */
  static ModInt calculate(long long N, int K) {
    Combination<ModInt> comb(K);

    ModInt res = 0;
    for (int i = 0; i <= K; ++i) {
      ModInt v = comb.C(K, i) * ModInt(i).pow(N);
      if ((K - i) % 2)
        res -= v;
      else
        res += v;
    }
    res *= comb.inverseFactorial(K);
    return res;
  }

  /**
   * @brief スターリング数を事前計算O(NK)
   * @param N
   * @param K
   */
  StirlingNumber(int N, int K) : res(N + 1, vector<ModInt>(K + 1, 0)) {
    res[0][0] = 1;
    for (int n = 1; n <= N; ++n) {
      for (int k = 1; k <= min(n, K); ++k) {
        res[n][k] = res[n - 1][k - 1] + res[n - 1][k] * k;
      }
    }
  }

  const vector<ModInt>& operator[](int n) const { return res[n]; }
};