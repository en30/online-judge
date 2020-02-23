#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ll N;
  cin >> N;

  unordered_map<ll, unordered_map<ll, ModInt>> memo;

  function<ModInt(ll, ll)> rec = [&](ll s, ll x) {
    if (memo[s].find(x) != memo[s].end()) return memo[s][x];
    if (s == 0) return ModInt(1);
    if (s == 1) {
      if (x == 0) return ModInt(1);
      return ModInt(2);
    }

    return memo[s][x] = rec(s / 2, x / 2) + rec((s - 1) / 2, (x - 1) / 2) +
                        rec((s - 2) / 2, x / 2);
  };

  cout << rec(N, N) << endl;

  return 0;
}
