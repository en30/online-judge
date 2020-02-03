#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"

int main() {
  int x[5][5];

  vector<int> pos(26, -1);
  for (int i = 0; i < (int)5; ++i)
    for (int j = 0; j < (int)5; ++j) {
      cin >> x[i][j];
      pos[x[i][j]] = 5 * i + j;
    }

  vector<int> dp(1 << 25, 0);
  dp[0] = 1;

  auto bit = [](int s, int r, int c) { return (s >> (r * 5 + c)) & 1; };
  auto valid = [&](int s, int j) {
    int r = j / 5, c = j % 5;
    if (0 < r && r < 4 && (bit(s, r - 1, c) ^ bit(s, r + 1, c))) return false;
    if (0 < c && c < 4 && (bit(s, r, c - 1) ^ bit(s, r, c + 1))) return false;
    return true;
  };

  for (int n = 1; n <= 25; ++n) {
    int s = first_fixed_size_subset(25, n - 1);
    do {
      if (pos[n] != -1) {
        int j = pos[n];
        if (!((s >> j) & 1) && valid(s, j)) {
          dp[s | (1 << j)] += dp[s];
          dp[s | (1 << j)] %= 1000000007;
        }

        continue;
      }

      for (int j = 0; j < (int)25; ++j) {
        if (!((s >> j) & 1) && valid(s, j)) {
          dp[s | (1 << j)] += dp[s];
          dp[s | (1 << j)] %= 1000000007;
        }
      }
    } while (next_fixed_size_subset(25, n - 1, s));
  }

  cout << dp[(1 << 25) - 1] << endl;

  return 0;
}
