#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> T(N);
  rep(i, N) cin >> T[i];
  int M;
  cin >> M;
  int S = accumulate(all(T), 0);
  rep(i, M) {
    int P, X;
    cin >> P >> X;
    --P;
    cout << S - (T[P] - X) << endl;
  }
  return 0;
}
