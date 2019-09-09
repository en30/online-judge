#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> p;
int main() {
  cin >> N;
  p.resize(N);
  rep(i, N) cin >> p[i];

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (p[i - 1] == i) {
      ans++;
      if (i <= N && p[i] == i + 1) ++i;
    }
  }

  cout << ans << endl;
  return 0;
}
