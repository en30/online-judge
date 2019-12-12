#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int N;
string X;

string flipAppend(string &S) {
  int L = S.size();
  string T = S + S;
  rep(i, L) T[i + L] = S[i] == '0' ? '1' : '0';
  return T;
}

int main() {
  ModInt::mod(998244353);

  cin >> N >> X;

  X = flipAppend(X);

  vector<int> periods;
  for (int r = 1; r <= sqrt(N); ++r) {
    if (N % r != 0) continue;
    int k = N / r;

    if (k % 2 != 0) periods.push_back(r);
    if (k != r && r % 2 != 0) periods.push_back(k);
  }
  sort(all(periods));

  mint two(2);
  vector<mint> c(periods.size(), 0);
  rep(i, periods.size()) {
    int t = periods[i];
    string Y = X.substr(0, t);

    rep(d, t) {
      if (Y[t - 1 - d] == '1') c[i] += two.pow(d);
    }

    string T = flipAppend(Y);
    string S = T;
    while (S.size() < X.size()) S += T;
    if (S <= X) c[i] += 1;

    rep(j, i) if (periods[i] % periods[j] == 0) c[i] -= c[j];
  }

  mint ans = 0;
  rep(i, periods.size()) ans += c[i] * 2 * periods[i];
  cout << ans << endl;

  return 0;
}
