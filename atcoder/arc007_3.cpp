#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string c;
  cin >> c;
  const int N = c.size();

  int base = 0;
  rep(i, N) {
    if (c[i] == 'o') base |= (1 << i);
  }

  int mask = (1 << N) - 1;
  vector<int> patterns(N);
  rep(i, N) {
    patterns[i] = (base >> i);
    patterns[i] |= (base & ((1 << i) - 1)) << (N - i);
  }

  int ans = N;
  rep(s, 1 << N) {
    int res = 0;
    rep(i, N) if ((s >> i) & 1) res |= patterns[i];
    if ((res & mask) == mask) chmin(ans, (int)bitset<10>(s).count());
  }

  cout << ans << endl;

  return 0;
}
