#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n;
  cin >> n;

  set<pair<char, int>> s;
  vector<int> color(n);
  int c = 0;

  rep(i, n) {
    char x;
    cin >> x;
    auto it = s.upper_bound(make_pair(x, n + 1));
    if (it == s.begin()) {
      s.emplace(x, ++c);
      color[i] = c;
    } else {
      it--;
      auto p = make_pair(x, it->second);
      s.erase(it);
      s.insert(p);
      color[i] = p.second;
    }
  }

  cout << c << endl;
  rep(i, n) {
    if (i) cout << " ";
    cout << color[i];
  }
  cout << endl;

  return 0;
}
