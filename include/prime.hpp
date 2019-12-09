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
