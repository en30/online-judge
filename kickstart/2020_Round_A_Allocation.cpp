#include <bits/stdc++.h>
#include "../include/template"

int solve() {
  int N, B;
  cin >> N >> B;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));

  int s = 0, i = 0;
  while (i < N && s + A[i] <= B) s += A[i++];
  return i;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) cout << "Case #" << i + 1 << ": " << solve() << endl;
  return 0;
}
