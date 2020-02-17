#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  rep(i, N) cin >> S[i];
  sort(all(S));
  rep(i, N) cout << S[i];
  cout << endl;
  return 0;
}
