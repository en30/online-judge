#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  const int R = 26;
  vector<set<int>> idx(R);
  rep(i, N) idx[S[i] - 'a'].insert(i);

  int Q;
  cin >> Q;
  rep(i, Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      idx[S[i] - 'a'].erase(i);
      S[i] = c;
      idx[c - 'a'].insert(i);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = 0;
      rep(c, R) {
        auto it = idx[c].lower_bound(l);
        if (it == idx[c].end()) continue;
        if (*it <= r) ++ans;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
