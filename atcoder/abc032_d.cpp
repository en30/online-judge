#include <bits/stdc++.h>
#include "../include/template"

int N, W;
vector<int> v, w;

struct Res {
  ll v, w;
  bool operator<(const Res& that) const { return w < that.w; }
};

void bruteForce() {
  int n1 = N / 2, n2 = N - n1;
  vector<Res> res(1 << n1, Res{0, 0});
  rep(s, 1 << n1) {
    rep(i, n1) if ((s >> i) & 1) {
      res[s].v += v[i];
      res[s].w += w[i];
    }
  }
  sort(all(res));
  vector<Res> cleaned;
  ll vm = 0;
  for (auto& r : res)
    if (chmax(vm, r.v)) cleaned.push_back(r);

  ll ans = 0;
  rep(s, 1 << n2) {
    Res r{0, 0};
    rep(i, n2) if ((s >> i) & 1) {
      r.v += v[n1 + i];
      r.w += w[n1 + i];
    }
    auto it = upper_bound(all(cleaned), Res{0, W - r.w});
    if (it == cleaned.begin()) {
      if (r.w <= W) chmax(ans, r.v);
    } else {
      it--;
      chmax(ans, it->v + r.v);
    }
  }

  cout << ans << endl;
}

void dpW() {
  int K = accumulate(all(w), 0);
  K = min(W, K);
  vector<ll> dp(K + 1, 0);
  rep(i, N) for (int j = K; j >= 0; --j) {
    if (j - w[i] >= 0) chmax(dp[j], dp[j - w[i]] + v[i]);
  }
  cout << dp[K] << endl;
}

void dpV() {
  int V = accumulate(all(v), 0);
  const ll INF = 1e18;
  vector<ll> dp(V + 1, INF);
  dp[0] = 0;
  rep(i, N) for (int j = V; j >= 0; --j) {
    if (j - v[i] >= 0) chmin(dp[j], dp[j - v[i]] + w[i]);
  }
  int ans = 0;
  rep(v, V + 1) if (dp[v] <= W) chmax(ans, v);
  cout << ans << endl;
}

int main() {
  cin >> N >> W;
  v.resize(N), w.resize(N);
  rep(i, N) cin >> v[i] >> w[i];

  if (N <= 30) {
    bruteForce();
  } else if ((*max_element(all(w))) <= 1000) {
    dpW();
  } else {
    dpV();
  }

  return 0;
}
