class PrimeTable {
  int N;
  vector<int> factor;

 public:
  vector<int> primes;
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

class Prime {
 public:
  class Factor {
   public:
    long long p, r;
  };

  static vector<Factor> factorize(long long n) {
    vector<Factor> res;
    long long m = n;
    for (long long i = 2; i * i <= m; i++) {
      if (m % i) continue;
      Factor f = Factor{i, 0};
      while (m % i == 0) {
        m /= i;
        f.r++;
      }
      res.push_back(f);
    }
    if (m != 1) {
      res.push_back(Factor{m, 1});
    }
    return res;
  }
};
