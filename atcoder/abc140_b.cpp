#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> A, C;

int main() {
  cin >> N;
  A.resize(N);
  C.resize(N);

  int ans = 0;

  rep(i, N) {
    cin >> A[i];
    A[i]--;
  }
  rep(i, N) {
    int B;
    cin >> B;
    ans += B;
  }

  rep(i, N - 1) cin >> C[i];

  for (int i = 1; i < N; ++i) {
    if (A[i] - A[i - 1] == 1) ans += C[A[i - 1]];
  }

  cout << ans << endl;
  return 0;
}
