#include <bits/stdc++.h>
#include "../include/template"
#include "../include/binary_indexed_tree.hpp"

int main() {
  int N;
  cin >> N;
  BinaryIndexedTree<ll> bit(1e5 + 1);

  ll ans = 0;
  rep(i, N) {
    int a;
    cin >> a;
    ans += i - bit.sum(a);
    bit.add(a, 1);
  }

  cout << ans << endl;
  return 0;
}
