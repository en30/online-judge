#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N, 0);
  rep(q, Q) {
    int L, R, T;
    cin >> L >> R >> T;
    --L, --R;
    for (int i = L; i <= R; ++i) a[i] = T;
  }

  rep(i, N) cout << a[i] << endl;
  return 0;
}
