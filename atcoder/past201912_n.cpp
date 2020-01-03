#include <bits/stdc++.h>
#include "../include/template"

int N, W, C;

struct Stone {
  int l, r, p;
};

int main() {
  cin >> N >> W >> C;

  ll sum = 0;
  ++N;
  vector<Stone> stones(N);
  stones[0] = Stone{0, 0, 0};
  rep(i, N - 1) {
    cin >> stones[i + 1].l >> stones[i + 1].r >> stones[i + 1].p;
    sum += stones[i + 1].p;
  }
  stones.push_back(Stone{W, W, 0});

  vector<int> l(stones.size()), r(stones.size());
  rep(i, stones.size()) {
    l[i] = stones[i].l;
    r[i] = stones[i].r;
  }
  sort(all(l));
  sort(all(r));

  vector<ll> SL(N + 1), SR(N + 1);
  sort(all(stones), [](const Stone& a, const Stone& b) { return a.l < b.l; });
  rep(i, N) SL[i + 1] = SL[i] + stones[i].p;

  sort(all(stones), [](const Stone& a, const Stone& b) { return a.r < b.r; });
  rep(i, N) SR[i + 1] = SR[i] + stones[i].p;

  ll p = 0;
  rep(i, N) {
    ll c = 0;

    int j = distance(r.begin(), upper_bound(all(r), stones[i].r));
    c += SR[j];
    j = distance(l.begin(), lower_bound(all(l), stones[i].r + C));
    if (j == l.size()) continue;
    c += SL[N] - SL[j];
    p = max(p, c);
  }

  cout << sum - p << endl;

  return 0;
}
