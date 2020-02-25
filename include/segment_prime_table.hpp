#pragma once

class SegmentPrimeTable {
  long long l, r;
  vector<long long> factor;

 public:
  /**
   * @brief [l, r)の素数表 O(sqrt(r) log log r)
   * @param l
   * @param r
   */
  SegmentPrimeTable(long long l, long long r) : l(l), r(r), factor(r - l) {
    assert(l < r);
    vector<int> smallFactor(sqrt(r), 0);
    for (long long i = l; i < r; ++i) factor[i - l] = i;
    for (int i = 2; (long long)i * i < r; ++i) {
      if (smallFactor[i]) continue;
      for (int j = 2 * i; (long long)j * j < r; j += i) smallFactor[j] = i;
      for (long long j = max(2LL, (l + i - 1) / i) * i; j < r; j += i)
        factor[j - l] = i;
    }
  }

  bool isPrime(long long k) {
    assert(l <= k && k < r);
    return factor[k - l] == k;
  }
};
