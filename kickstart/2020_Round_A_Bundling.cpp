#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<string> S;
// [l, r)
int score(auto l, auto r, int d) {
  int s = 0;

  auto charLess = [&](const string& a, const string& b) { return a[d] < b[d]; };
  sort(l, r, charLess);

  int n = r - l;
  for (char c = 'A'; c <= 'Z'; c++) {
    auto nl = lower_bound(l, r, string(d + 1, c), charLess);
    auto nr = upper_bound(l, r, string(d + 1, c), charLess);
    int m = nr - nl;
    if (m >= K) {
      s += score(nl, nr, d + 1);
      n -= (m / K) * K;
    }
  }
  s += (n / K) * d;
  return s;
}

int solve() {
  cin >> N >> K;
  S.resize(N);
  rep(i, N) {
    cin >> S[i];
    S[i] += 'a';
  }

  return score(S.begin(), S.end(), 0);
}

int main() {
  int T;
  cin >> T;
  rep(i, T) cout << "Case #" << i + 1 << ": " << solve() << endl;
  return 0;
}
