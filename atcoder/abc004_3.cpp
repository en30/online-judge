#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  N %= 30;

  int a[6] = {1, 2, 3, 4, 5, 6};
  rep(i, N) swap(a[i % 5], a[i % 5 + 1]);

  rep(i, 6) cout << a[i];
  cout << endl;

  return 0;
}
