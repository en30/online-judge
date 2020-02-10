#pragma once
#include "./template"

class Knapsack {
  int N;
  ll W;
  vector<ll> value, weight;
  struct Res {
    ll v, w;
    bool operator<(const Res& that) const { return w < that.w; }
  };

 public:
  Knapsack(const vector<ll>& value, const vector<ll>& weight, ll W)
      : value(value), weight(weight), N(value.size()), W(W) {}

  /**
   * @brief 半分全列挙 O(N2^(N/2))
   * @return
   */
  ll splitAndList() {
    int n1 = N / 2, n2 = N - n1;
    vector<Res> res(1 << n1, Res{0, 0});
    rep(s, 1 << n1) {
      rep(i, n1) if ((s >> i) & 1) {
        res[s].v += value[i];
        res[s].w += weight[i];
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
        r.v += value[n1 + i];
        r.w += weight[n1 + i];
      }
      auto it = upper_bound(all(cleaned), Res{0, W - r.w});
      if (it == cleaned.begin()) {
        if (r.w <= W) chmax(ans, r.v);
      } else {
        it--;
        chmax(ans, it->v + r.v);
      }
    }
    return ans;
  }

  /**
   * @brief DP O(N*min(W, sum(weight))
   * @return
   */
  ll valueMaximizationDP() {
    ll K = min(W, accumulate(all(weight), 0LL));
    vector<ll> dp(K + 1, 0);
    rep(i, N) for (int j = K; j >= 0; --j) {
      if (j - weight[i] >= 0) chmax(dp[j], dp[j - weight[i]] + value[i]);
    }
    return dp[K];
  }

  /**
   * @brief DP O(N*sum(value))
   * @return
   */
  ll weightMinimizationDP() {
    ll V = accumulate(all(value), 0LL);
    ll INF = 1e18;
    vector<ll> dp(V + 1, INF);
    dp[0] = 0;
    rep(i, N) for (int j = V; j >= 0; --j) {
      if (j - value[i] >= 0) chmin(dp[j], dp[j - value[i]] + weight[i]);
    }
    ll ans = 0;
    for (ll v = 0; v < V + 1; ++v)
      if (dp[v] <= W) chmax(ans, v);
    return ans;
  }
};