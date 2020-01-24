#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int R, C, K, N;
  cin >> R >> C >> K >> N;

  vector<pair<int, int>> candies;
  vector<int> rc(R, 0), cc(C, 0);
  rep(i, N) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    candies.emplace_back(r, c);
    rc[r] += 1;
    cc[c] += 1;
  }

  vector<int> ccs(cc);
  sort(all(ccs));

  ll ans = 0;
  rep(i, R) {
    int t = K - rc[i];
    auto p = equal_range(all(ccs), t);
    ans += p.second - p.first;
  }

  for (auto& c : candies) {
    int k = rc[c.first] + cc[c.second];
    if (k == K + 1) ++ans;
    if (k == K) --ans;
  }

  cout << ans << endl;

  return 0;
}
