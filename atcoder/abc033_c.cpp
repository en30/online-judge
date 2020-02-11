#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;

  int N = S.size();
  int i = 0, ans = 0;
  bool zero = false;
  while (i <= N) {
    if (i == N || S[i] == '+') {
      if (!zero) ++ans;
      zero = false;
    } else if (S[i] == '0') {
      zero = true;
    }

    ++i;
  }

  cout << ans << endl;

  return 0;
}
