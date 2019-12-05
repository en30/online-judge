#include <bits/stdc++.h>
#include "../include/template"

int t;
int n;
int p[400001];

string solve() {
  cin >> n;
  set<int> cands;
  rep(i, n) {
    cin >> p[i];
    if (i > 0 && i <= n / 2 && p[i] < p[i - 1]) cands.insert(i);
  }

  if (cands.size() == 0) return "0 0 0";

  int g = *cands.begin();

  auto it = cands.upper_bound(2 * g);
  if (it == cands.end()) return "0 0 0";
  int s = (*it) - g;

  it = cands.end();
  it--;
  int b = (*it) - g - s;

  if (b > 0 && b > g) {
    stringstream ss;
    ss << g << " " << s << " " << b;
    return ss.str();
  } else {
    return "0 0 0";
  }
}

int main() {
  cin >> t;
  rep(i, t) cout << solve() << endl;
  return 0;
}
