#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int k;
  cin >> k;
 
  vector<int> R(8, -1);
  rep(i, k) {
    int r, c;
    cin >> r >> c;
    R[r] = c;
  }

  vector<int> perm(8);
  rep(i, 8) perm[i] = i;

  auto good = [&](const vector<int>& p) {
    set<int> d1, d2;
    rep(r, 8) {
      if (R[r] != -1 && R[r] != p[r]) return false;
      d1.insert(p[r] + r);
      d2.insert(p[r] - r);
    }
    return d1.size() == 8 && d2.size() == 8;
  };

  do {
    if (good(perm)) {
      rep(i, 8) {
        rep(j, 8) cout << (perm[i] == j ? 'Q' : '.');
        cout << endl;
      }
      break;
    }
  } while (next_permutation(all(perm)));

  return 0;
}
