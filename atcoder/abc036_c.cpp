#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  vector<int> c(a);
  sort(all(c));
  c.erase(unique(all(c)), c.end());

  rep(i, N) cout << distance(c.begin(), lower_bound(all(c), a[i])) << endl;

  return 0;
}
