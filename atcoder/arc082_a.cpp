#include <bits/stdc++.h>
#include "../include/template"

int N;
unordered_map<int, int> c;

int main() {
  cin >> N;
  rep(i, N) {
    int a;
    cin >> a;
    c[a]++;
  }

  int ans = 0;
  rep(x, 1e5 + 1) {
    int res = c[x];
    if (x - 1 >= 0) res += c[x - 1];
    if (x + 1 <= 1e5) res += c[x + 1];
    ans = max(ans, res);
  }

  cout << ans << endl;

  return 0;
}
