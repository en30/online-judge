#include <bits/stdc++.h>
#include "../include/template"

int n;

int main() {
  cin >> n;

  vector<int> cnt(1000001, 0);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    cnt[a] += 1;
    cnt[b + 1] -= 1;
  }
  rep(i, 1000001) cnt[i + 1] += cnt[i];

  cout << *max_element(all(cnt)) << endl;

  return 0;
}
