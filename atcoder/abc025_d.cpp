#include <bits/stdc++.h>
#include "../include/template"

const int MOD = 1000000007;
int main() {
  int x[5][5];

  vector<int> pos(26, -1), cand;
  rep(i, 5) rep(j, 5) {
    cin >> x[i][j];
    if (x[i][j]) {
      pos[x[i][j]] = 5 * i + j;
    } else {
      cand.push_back(i * 5 + j);
    }
  }

  int M = cand.size();
  vector<int> memo(1 << M, -1);
  auto compress = [&](int s) {
    int t = 0;
    rep(i, cand.size()) {
      if ((s >> cand[i]) & 1) t |= 1 << i;
    }
    return t;
  };

  auto bit = [](int s, int r, int c) { return (s >> (r * 5 + c)) & 1; };
  auto valid = [&](int s, int j) {
    if ((s >> j) & 1) return false;
    int r = j / 5, c = j % 5;
    if (0 < r && r < 4 && (bit(s, r - 1, c) ^ bit(s, r + 1, c))) return false;
    if (0 < c && c < 4 && (bit(s, r, c - 1) ^ bit(s, r, c + 1))) return false;
    return true;
  };

  function<int(int, int)> f = [&](int s, int n) {
    if (n == 25) return 1;
    int t = compress(s);
    if (memo[t] != -1) return memo[t];

    if (pos[n] != -1) {
      if (!valid(s, pos[n])) return 0;
      return f(s | (1 << pos[n]), n + 1);
    }

    int res = 0;
    for (int i : cand) {
      if (valid(s, i)) {
        res += f(s | (1 << i), n + 1);
        res %= MOD;
      }
    }
    return memo[t] = res;
  };

  cout << f(0, 1) << endl;

  return 0;
}
