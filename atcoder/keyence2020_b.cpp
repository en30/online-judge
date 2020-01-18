#include <bits/stdc++.h>
#include "../include/template"

int N;
struct Robot {
  ll X, L;
};

int main() {
  cin >> N;
  vector<Robot> R(N);
  rep(i, N) cin >> R[i].X >> R[i].L;

  sort(all(R),
       [&](const Robot& a, const Robot& b) { return a.X + a.L < b.X + b.L; });

  ll ans = 0, x = -1e10;
  rep(i, N) {
    if (x <= R[i].X - R[i].L) {
      ++ans;
      x = R[i].X + R[i].L;
    }
  }

  cout << ans << endl;
  return 0;
}
