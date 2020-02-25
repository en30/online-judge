#pragma once

class PrimeTable {
  int N;
  vector<int> factor;

 public:
  vector<int> primes;
  /**
   * @brief エラトステネスの篩による素数表O(N log log N)
   * @param N
   */
  PrimeTable(int N) : N(N), factor(N + 1, 0) {
    factor[0] = factor[1] = -1;
    for (long long i = 2; i <= N; ++i) {
      if (factor[i]) continue;
      primes.push_back(i);
      factor[i] = i;
      for (long long j = i * i; j <= N; j += i)
        if (!factor[j]) factor[j] = i;
    }
  }

  bool isPrime(int k) { return factor[k] == k; }

  unordered_map<int, int> factorize(int k) {
    assert(k <= N);
    unordered_map<int, int> res;
    while (k != 1) {
      res[factor[k]] += 1;
      k /= factor[k];
    }
    return res;
  }
};
