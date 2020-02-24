#include <bits/stdc++.h>
#include "../include/template"

const int M = 3e4;

void solve() {}

int main() {
  int t;
  cin >> t;

  vector<vector<int>> divs(M + 1);
  for (int m = 1; m <= M; ++m) {
    for (int i = 1; i * i <= m; ++i) {
      if (m % i == 0) {
        divs[m].push_back(i);
        if (i != m / i) divs[m].push_back(m / i);
      }
    }
    sort(all(divs[m]));
  }

  rep(i, t) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ans(3);

    int m = 1e9;
    for (int B = 1; B <= M; ++B) {
      int A, C;
      auto it = lower_bound(all(divs[B]), a);
      if (it == divs[B].end() ||
          (it != divs[B].begin() && abs(*prev(it) - a) < abs(*it - a))) {
        A = *prev(it);
      } else {
        A = *it;
      }

      int d = c / B;
      C = d * B;
      if (abs((d + 1) * B - c) < abs(C - c)) C = (d + 1) * B;

      if (chmin(m, abs(a - A) + abs(b - B) + abs(c - C))) {
        ans[0] = A;
        ans[1] = B;
        ans[2] = C;
      }
    }
    cout << m << endl;
    rep(i, 3) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
