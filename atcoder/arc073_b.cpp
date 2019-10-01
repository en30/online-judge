#include <bits/stdc++.h>
#include "../include/template"

int N, W;
struct Item {
  ll w, v;

  bool operator<(const Item &that) const { return v > that.v; }
};

vector<Item> items;
int main() {
  cin >> N >> W;
  items.resize(N);
  rep(i, N) cin >> items[i].w >> items[i].v;

  vector<Item> s[4];
  rep(i, N) { s[items[i].w - items[0].w].push_back(items[i]); }
  rep(i, 4) sort(all(s[i]));

  vector<vector<ll>> sw(4, vector<ll>(N + 1, 0)), sv(4, vector<ll>(N + 1, 0));
  rep(i, 4) rep(j, N) {
    sw[i][j + 1] = sw[i][j] + (j < s[i].size() ? s[i][j].w : 0);
    sv[i][j + 1] = sv[i][j] + (j < s[i].size() ? s[i][j].v : 0);
  }

  ll ans = 0;
  rep(i, N + 1) rep(j, N + 1) rep(k, N + 1) rep(l, N + 1) {
    ll w = sw[0][i] + sw[1][j] + sw[2][k] + sw[3][l];
    if (w > W) continue;
    ans = max(ans, sv[0][i] + sv[1][j] + sv[2][k] + sv[3][l]);
  }

  cout << ans << endl;
  return 0;
}
