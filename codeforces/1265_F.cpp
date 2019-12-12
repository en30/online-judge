#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

using mint = ModInt;

string S;

int main() {
  ModInt::mod(998244353);

  cin >> S;

  int N = S.size();

  int M = 0;
  rep(i, N) M += (S[i] == '?');

  vector<int> L(N + 1, 0), R(N + 1, 0);
  rep(i, N) {
    L[i + 1] = L[i] + (S[i] != ')');
    R[N - i - 1] = R[N - i] + (S[N - i - 1] == ')');
  }

  Combination<mint> comb(M + 1);

  vector<mint> SB(M + 2, 0), SQ(M + 1, 0);
  rep(i, M + 1) SB[i + 1] = SB[i] + comb.C(M, i);
  rep(i, M) SQ[i + 1] = SQ[i] + comb.C(M - 1, i);

  mint ans = 0;
  rep(i, N) {
    if (S[i] == ')') continue;

    int k = L[i + 1] - R[i + 1];

    if (S[i] == '(') ans += SB[M + 1] - SB[min(M + 1, max(k, 0))];
    if (S[i] == '?') ans += SQ[M] - SQ[min(M, max(k, 0))];
  }

  cout << ans << endl;

  return 0;
}
