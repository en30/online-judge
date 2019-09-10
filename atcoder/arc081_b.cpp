#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

const ll MOD = 1000000007;
using mint = ModInt<MOD>;

int N;
vector<string> S(2);
int main() {
  cin >> N;
  cin >> S[0] >> S[1];

  mint ans = (S[0][0] == S[1][0] ? 3 : 6);
  rep(i, N - 1) {
    if (S[0][i] == S[0][i + 1] && S[1][i] == S[1][i + 1]) continue;

    if (S[0][i] == S[1][i]) {
      ans *= 2;
    } else if (S[0][i + 1] != S[1][i + 1]) {
      ans *= 3;
    }
  }

  cout << ans << endl;

  return 0;
}
