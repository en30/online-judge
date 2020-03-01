#include <bits/stdc++.h>
#include "../include/template"
#include "../include/stirling_number.hpp"

int main() {
  ll N;
  int M;
  cin >> N >> M;
  Combination<ModInt> comb(M);
  cout << comb.factorial(M) * StirlingNumber::calculate(N, M) << endl;
  return 0;
}