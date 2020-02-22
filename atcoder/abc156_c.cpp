#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  rep(i, N) cin >> X[i];

  int s = accumulate(all(X), 0);
  double r = double(s) / N;

  auto score = [&](int r) {
    int res = 0;
    rep(i, N) res += (r - X[i]) * (r - X[i]);
    return res;
  };
  cout << min(score(floor(r)), score(ceil(r))) << endl;

  return 0;
}
