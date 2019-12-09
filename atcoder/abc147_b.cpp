#include <bits/stdc++.h>
#include "../include/template"

string S;

int main() {
  cin >> S;

  int N = S.size();
  int ans = 0;

  for (int i = 0; i < N / 2; ++i) {
    ans += S[i] != S[N - 1 - i];
  }

  cout << ans << endl;
  return 0;
}
