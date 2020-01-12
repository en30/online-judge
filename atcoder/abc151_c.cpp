#include <bits/stdc++.h>
#include "../include/template"

int N, M;

int main() {
  cin >> N >> M;

  vector<vector<int>> res(N);
  rep(i, M) {
    int p;
    string S;
    cin >> p >> S;
    res[p - 1].push_back(S == "AC");
  }

  int ac = 0;
  int p = 0;
  rep(i, N) {
    bool ok = false;
    int cp = 0;

    for (int r : res[i]) {
      if (!ok) {
        if (r) {
          ok = true;
          p += cp;
          ++ac;
        } else {
          ++cp;
        }
      }
    }
  }

  cout << ac << " " << p << endl;

  return 0;
}
