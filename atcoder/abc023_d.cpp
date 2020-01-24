#include <bits/stdc++.h>
#include "../include/template"
#include "../include/counting_sort.hpp"

struct Balloon {
  ll H, S;
};

int main() {
  int N;
  cin >> N;
  vector<Balloon> B(N);
  rep(i, N) cin >> B[i].H >> B[i].S;

  auto achievable = [&](ll s) {
    vector<int> ts(N);
    rep(i, N) {
      if (s - B[i].H < 0) return false;
      ll t = (s - B[i].H) / B[i].S;
      ts[i] = t >= N - 1 ? N - 1 : t;
    }
    ts = countingSort(ts, N - 1);
    rep(i, N) if (ts[i] < i) return false;
    return true;
  };

  ll l = 0, r = 1e15;
  while (r - l > 1LL) {
    ll m = (l + r) / 2LL;
    if (achievable(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r << endl;

  return 0;
}
