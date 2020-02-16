#include <bits/stdc++.h>
#include "../include/template"

struct Bomb {
  int x, on;
};

struct Switch {
  int l, r;
};

struct Edge {
  int from, to, iSwitch;
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<Bomb> bombs(N);
  rep(i, N) cin >> bombs[i].x >> bombs[i].on;

  auto lessX = [](const Bomb& a, const Bomb& b) { return a.x < b.x; };

  sort(all(bombs), lessX);

  vector<Switch> switches(M);
  rep(i, M) {
    int L, R;
    cin >> L >> R;
    switches[i].l =
        distance(bombs.begin(), lower_bound(all(bombs), Bomb{L, 0}, lessX));
    switches[i].r =
        distance(bombs.begin(), upper_bound(all(bombs), Bomb{R, 0}, lessX)) - 1;
  }

  vector<int> diff(N + 1, 0);
  rep(i, N + 1) {
    diff[i] = (i == 0 ? 0 : bombs[i - 1].on) ^ (i == N ? 0 : bombs[i].on);
  }

  vector<vector<Edge>> G(N + 1);
  rep(i, M) {
    int u = switches[i].l, v = switches[i].r + 1;
    G[u].push_back(Edge{u, v, i});
    G[v].push_back(Edge{v, u, i});
  }

  vector<bool> used(N + 1, false);
  vector<int> ans;

  function<bool(int)> leftOne = [&](int u) {
    used[u] = true;

    bool res = diff[u];
    for (Edge& e : G[u]) {
      if (used[e.to]) continue;
      if (leftOne(e.to)) {
        ans.push_back(e.iSwitch);
        res ^= 1;
      }
    }
    return res;
  };

  rep(i, N + 1) {
    if (used[i]) continue;
    if (leftOne(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  int k = ans.size();
  cout << k << endl;
  sort(all(ans));
  rep(i, k) {
    if (i) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;

  return 0;
}
