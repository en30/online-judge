#include <bits/stdc++.h>
#include "../include/template"

int N;

struct R {
  int i, p;
  string s;
};
int main() {
  cin >> N;
  vector<R> rs(N);
  rep(i, N) {
    cin >> rs[i].s >> rs[i].p;
    rs[i].i = i + 1;
  }
  sort(all(rs), [&](const R& a, const R& b) {
    return a.s == b.s ? a.p > b.p : a.s < b.s;
  });

  rep(i, N) cout << rs[i].i << endl;
  return 0;
}
