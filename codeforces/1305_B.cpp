#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;

  const int N = s.size();

  int r = N - 1;
  vector<int> ans;
  for (int l = 0; l < r && l < N; ++l) {
    if (s[l] != '(') continue;
    while (l < r && s[r] != ')') --r;
    if (l >= r) break;
    ans.push_back(l + 1);
    ans.push_back(r + 1);
    --r;
  }

  sort(all(ans));
  if (ans.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  cout << 1 << endl;
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
