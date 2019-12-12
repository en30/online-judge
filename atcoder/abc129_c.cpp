#include <bits/stdc++.h>
#include "../include/template"

const int MOD = 1e9 + 7;

int N, M;

int main() {
  cin >> N >> M;

  vector<bool> broken(N, false);
  rep(i, M) {
    int a;
    cin >> a;
    broken[a] = true;
  }

  vector<int> c(N + 1, 0);
  c[0] = 1;
  rep(i, N) {
    if (i + 1 <= N && !broken[i + 1]) c[i + 1] = (c[i + 1] + c[i]) % MOD;
    if (i + 2 <= N && !broken[i + 2]) c[i + 2] = (c[i + 2] + c[i]) % MOD;
  }

  cout << c[N] << endl;

  return 0;
}
