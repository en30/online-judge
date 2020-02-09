#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"

int K, N;
vector<string> v, w;

void dfs(int r, int iv, int iw, vector<string> res) {
  if (r == N) {
    for (string &s : res) {
      cout << s << endl;
    }
    exit(0);
  }

  if (v[r].size() == iv && w[r].size() == iw) {
    dfs(r + 1, 0, 0, res);
    return;
  }
  if (v[r].size() == iv || w[r].size() == iw) return;

  int c = v[r][iv] - '1';
  if (res[c] == "") {
    rep(i, 3) {
      if (iw + i >= w[r].size()) break;
      res[c] += w[r][iw + i];
      dfs(r, iv + 1, iw + i + 1, res);
    }
  } else {
    rep(i, res[c].size()) if (iw + i >= w[r].size() ||
                              w[r][iw + i] != res[c][i]) return;
    dfs(r, iv + 1, iw + res[c].size(), res);
  }
}

int main() {
  cin >> K >> N;
  v.resize(N), w.resize(N);
  rep(i, N) cin >> v[i] >> w[i];

  dfs(0, 0, 0, vector<string>(K, ""));
  return 0;
}
