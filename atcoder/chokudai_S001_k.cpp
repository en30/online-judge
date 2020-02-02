#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"
#include "../include/binary_indexed_tree.hpp"

int main() {
  int N;
  cin >> N;

  BinaryIndexedTree<int> bit(N + 1);
  Combination<ModInt> comb(N);

  rep(i, N) bit.add(i + 1, 1);

  ModInt ans = 1;
  rep(i, N) {
    int a;
    cin >> a;
    ans += comb.factorial(N - 1 - i) * bit.sum(a);
    bit.add(a, -1);
  }

  cout << ans << endl;

  return 0;
}
