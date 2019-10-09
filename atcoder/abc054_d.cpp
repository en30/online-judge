#include <bits/stdc++.h>
#include "../include/template"

int N, Ma, Mb;

struct Chemical {
  int w, c;
};

int main() {
  cin >> N >> Ma >> Mb;

  vector<Chemical> chems(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b >> chems[i].c;
    chems[i].w = a * Mb - b * Ma;
  }

  sort(all(chems),
       [](const Chemical &a, const Chemical &b) { return a.w > b.w; });

  const int W = 4001;
  const int INF = 1e9;
  int dp[41][W];
  rep(i, N) rep(j, W) dp[i][j] = INF;
  dp[0][0] = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i, N) {
    rep(j, W) {
      if (dp[i][j] != INF) {
        int nj = j + chems[i].w;
        if (nj >= 0) dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + chems[i].c);
        if (nj == 0) pq.push(dp[i][j] + chems[i].c);
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      }
    }
  }

  cout << (pq.empty() ? -1 : pq.top()) << endl;

  return 0;
}
