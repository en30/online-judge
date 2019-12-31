#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  unordered_map<string, int> c;
  rep(i, N) {
    string s;
    cin >> s;
    c[s] += 1;
  }
  int m = 0;
  string ans;
  for (auto it = c.begin(); it != c.end(); it++) {
    if (m < it->second) {
      ans = it->first;
      m = it->second;
    }
  }

  cout << ans << endl;

  return 0;
}
