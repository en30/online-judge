#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  int N;
  cin >> N;
  vector<int> C(N, 0);

  rep(i, N) {
    int A;
    cin >> A;
    C[A] += 1;
  }

  auto ans = [&]() -> ll {
    rep(i, N) {
      if (i == 0 && (N % 2) && C[i] == 1) continue;
      if (((N % 2) ^ (i % 2)) && C[i] == 2) continue;
      if (C[i] == 0) continue;
      return 0;
    }
    return ModInt(2).pow(N / 2).val();
  };

  cout << ans() << endl;
  return 0;
}
