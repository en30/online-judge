#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> c(n, 0);

  rep(i, n) c[i] += 1;
  int k = 0;
  rep(i, n) k += c[i] * i;
  if (d > k) {
    cout << "NO" << endl;
    return;
  };

  for (int i = n - 1; k != d && i > 0; --i) {
    for (int j = i - 1; k != d && j > 0 && c[j] < 2 * c[j - 1]; --j) {
      --c[j + 1];
      ++c[j];
      --k;
    }
  }

  if (k != d) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  int v = 2;
  vector<int> prev(1, 1), curr;
  vector<int> p(n + 1);
  for (int i = 1; i < n; ++i) {
    curr.clear();
    for (int j = 0; j < c[i]; ++j) {
      p[v] = prev[j / 2];
      curr.push_back(v);
      ++v;
    }
    swap(prev, curr);
  }
  for (int i = 2; i <= n; ++i) {
    if (i != 2) cout << " ";
    cout << p[i];
  }
  cout << endl;
};

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();

  return 0;
}
