#include <bits/stdc++.h>
#include "../include/template"

int N;

struct Statement {
  int x, y;
};

int main() {
  cin >> N;
  vector<int> A(N);
  vector<vector<Statement>> s(N);

  rep(i, N) {
    cin >> A[i];
    s[i].resize(A[i]);
    rep(j, A[i]) {
      cin >> s[i][j].x >> s[i][j].y;
      --s[i][j].x;
    }
  }

  int ans = 0;
  rep(i, (1 << N)) {
    bool valid = true;
    bitset<20> b(i);
    rep(j, N) {
      if (b[j]) rep(k, A[j]) {
          if (b[s[j][k].x] != s[j][k].y) {
            valid = false;
          }
        }
    }

    if (valid) ans = max(ans, (int)b.count());
  }

  cout << ans << endl;

  return 0;
}
