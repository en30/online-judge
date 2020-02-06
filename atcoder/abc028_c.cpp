#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"

int main() {
  vector<int> a(5), v;
  rep(i, 5) cin >> a[i];

  int s = first_fixed_size_subset(5, 3);
  do {
    int c = 0;
    rep(i, 5) {
      if ((s >> i) & 1) c += a[i];
    }
    v.push_back(c);
  } while (next_fixed_size_subset(5, 3, s));

  sort(all(v));

  cout << v[v.size() - 3] << endl;
  return 0;
}
