#include <bits/stdc++.h>
#include "../include/template"

string S;
int N;

int main() {
  cin >> S >> N;

  rep(i, N) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    reverse(S.begin() + l, S.begin() + r + 1);
  }

  cout << S << endl;
  return 0;
}
