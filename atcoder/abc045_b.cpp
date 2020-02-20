#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<string> S(3);
  rep(i, 3) cin >> S[i];

  function<int(int)> winner = [&](int i) {
    if (S[i].size() == 0) return i;
    int ni = S[i][0] - 'a';
    S[i] = S[i].substr(1);
    return winner(ni);
  };

  cout << char(winner(0) + 'A') << endl;
  return 0;
}
