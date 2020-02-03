#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  int N;
  cin >> S >> N;

  rep(i, 5) rep(j, 5) {
    if (i * 5 + j == N - 1) {
      cout << S[i] << S[j] << endl;
      return 0;
    }
  }

  return 0;
}
