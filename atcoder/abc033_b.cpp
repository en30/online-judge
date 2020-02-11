#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> P(N);
  rep(i, N) cin >> S[i] >> P[i];
  int sum = accumulate(all(P), 0);
  rep(i, N) {
    if (2 * P[i] > sum) {
      cout << S[i] << endl;
      return 0;
    }
  }
  cout << "atcoder" << endl;

  return 0;
}
