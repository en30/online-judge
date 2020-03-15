#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int A = a.size(), B = b.size(), C = c.size();

  auto match = [](char c1, char c2) -> bool {
    return c1 == '?' || c2 == '?' || c1 == c2;
  };

  const int M = 2000;
  const int OFFSET = 4 * M;
  vector<bool> matchAB(2 * OFFSET + 1, true), matchAC(2 * OFFSET + 1, true),
      matchBC(2 * OFFSET + 1, true);

  rep(i, A) rep(j, B) if (!match(a[i], b[j])) matchAB[OFFSET - j + i] = false;
  rep(i, A) rep(j, C) if (!match(a[i], c[j])) matchAC[OFFSET - j + i] = false;
  rep(i, B) rep(j, C) if (!match(b[i], c[j])) matchBC[OFFSET - j + i] = false;

  int ans = 3 * M;
  for (int ab = -B - C; ab <= A + C; ++ab) {
    for (int ac = -C - B; ac <= A + B; ++ac) {
      if (!matchAB[OFFSET + ab] || !matchAC[OFFSET + ac] ||
          !matchBC[OFFSET + ac - ab])
        continue;
      int r = max({A, ab + B, ac + C});
      int l = min({0, ab, ac});
      chmin(ans, r - l);
    }
  }
  cout << ans << endl;

  return 0;
}
