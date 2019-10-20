#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> L;

int main() {
  cin >> N;
  L.resize(N);
  rep(i, N) cin >> L[i];

  sort(all(L));

  ll ans = 0;
  for (auto it = L.begin(); it != L.end(); it++) {
    for (auto it2 = next(it); it2 != L.end(); it2++) {
      ans += distance(upper_bound(it2, L.end(), abs(*it - *it2)),
                      lower_bound(it2, L.end(), *it + *it2)) -
             1;
    }
  }

  cout << ans << endl;
  return 0;
}
