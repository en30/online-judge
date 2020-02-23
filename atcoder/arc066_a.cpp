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
    ModInt res = 1;
    if (N % 2 == 0) {
      rep(i, N) {
        if (i % 2 == 0) {
          if (C[i] != 0) return 0;
        } else {
          if (C[i] != 2) return 0;
          res *= C[i];
        }
      }
    } else {
      rep(i, N) {
        if (i % 2 == 0) {
          if (i == 0 && C[i] != 1) return 0;
          if (i != 0 && C[i] != 2) return 0;
          res *= C[i];
        } else {
          if (C[i] != 0) return 0;
        }
      }
    }
    return res.val();
  };

  cout << ans() << endl;
  return 0;
}
