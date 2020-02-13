#include <bits/stdc++.h>
#include "../include/template"

const int R = 26;

void solve() {
  string s;
  cin >> s;

  vector<set<int>> G(R);
  int N = s.size();
  rep(i, N - 1) {
    G[s[i] - 'a'].insert(s[i + 1] - 'a');
    G[s[i + 1] - 'a'].insert(s[i] - 'a');
  }

  vector<bool> used(R, false);
  string ans = "";

  function<bool(int, int)> rec = [&](int u, int p) {
    used[u] = true;
    if (p != -1) {
      G[u].erase(p);
      G[p].erase(u);
    }
    ans += 'a' + u;
    if (G[u].size() == 0) return true;
    if (G[u].size() > 1) return false;
    return rec((*G[u].begin()), u);
  };

  rep(i, R) {
    if (!used[i] && G[i].size() == 1 && !rec(i, -1)) {
      cout << "NO" << endl;
      return;
    }
  }

  rep(i, R) if (!used[i] && G[i].size() != 0) {
    cout << "NO" << endl;
    return;
  }

  rep(i, R) if (!used[i]) ans += 'a' + i;

  cout << "YES" << endl;
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) solve();
  return 0;
}
