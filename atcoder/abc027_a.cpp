#include <bits/stdc++.h>
#include "../include/template"

int main() {
  unordered_map<int, int> m;
  rep(i, 3) {
    int l;
    cin >> l;
    ++m[l];
  }
  auto it = m.begin();
  cout << (it->second % 2 == 1 ? it->first : next(it)->first) << endl;

  return 0;
}
