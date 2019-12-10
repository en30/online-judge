#include <bits/stdc++.h>
#include "../include/template"

int N, M;

int main() {
  cin >> N >> M;

  vector<vector<int>> sw(M);
  rep(i, M) {
    int k;
    cin >> k;
    rep(j, k) {
      int s;
      cin >> s;
      sw[i].push_back(s - 1);
    }
  }

  vector<int> p(M);
  rep(i, M) cin >> p[i];

  int ans = 0;
  rep(i, (1 << N)) {
    bitset<10> s(i);

    bool allOn = true;
    rep(j, M) {
      int c = 0;
      for (int t : sw[j])
        if (s[t]) ++c;
      if (c % 2 != p[j]) allOn = false;
    }
    if (allOn) ++ans;
  }

  cout << ans << endl;

  return 0;
}
