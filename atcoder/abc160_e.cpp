#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> p(A), q(B), r(C);
  rep(i, A) cin >> p[i];
  rep(i, B) cin >> q[i];
  rep(i, C) cin >> r[i];
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());

  vector<int> cands;
  rep(i, min(X, A)) cands.push_back(p[i]);
  rep(i, min(Y, B)) cands.push_back(q[i]);
  rep(i, min(X + Y, C)) cands.push_back(r[i]);
  sort(cands.rbegin(), cands.rend());

  ll ans = 0;
  rep(i, X + Y) ans += cands[i];
  cout << ans << endl;

  return 0;
}
