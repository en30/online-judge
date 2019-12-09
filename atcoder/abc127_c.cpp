#include <bits/stdc++.h>
#include "../include/template"

int N, M;
int main() {
  cin >> N >> M;

  vector<int> c(N + 1, 0);
  rep(i, M) {
    int L, R;
    cin >> L >> R;
    --L, --R;
    c[L] += 1;
    c[R + 1] -= 1;
  }

  rep(i, N) c[i + 1] += c[i];

  int ans = 0;
  rep(i, N) ans += (c[i] == M);

  cout << ans << endl;
  return 0;
}
