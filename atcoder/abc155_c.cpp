#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  map<string, int> h;
  rep(i, N) {
    string S;
    cin >> S;
    h[S] += 1;
  }
  int m = 0;
  for (auto& p : h) chmax(m, p.second);

  set<string> ans;
  for (auto& p : h)
    if (p.second == m) ans.insert(p.first);

  for (string s : ans) cout << s << endl;

  return 0;
}
