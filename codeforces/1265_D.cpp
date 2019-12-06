#include <bits/stdc++.h>
#include "../include/template"

int cnt[4];

vector<vector<int>> G;

bool simulate(int i) {
  --cnt[i];
  for (int j : G[i]) {
    if (cnt[j] == 0) continue;
    bool valid = simulate(j);
    ++cnt[i];
    if (valid) cout << " " << i;
    return valid;
  }

  bool valid = true;
  rep(i, 4) valid &= (cnt[i] == 0);
  if (valid) {
    cout << "YES" << endl;
    cout << i;
  }
  ++cnt[i];
  return valid;
}

int main() {
  rep(i, 4) cin >> cnt[i];

  G.resize(4);
  rep(i, 4) {
    if (i - 1 >= 0) G[i].push_back(i - 1);
    if (i + 1 < 4) G[i].push_back(i + 1);
  }

  rep(i, 4) {
    if (simulate(i)) {
      cout << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}
