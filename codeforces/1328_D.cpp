#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  scanf("%d", &n);
  set<int> s;
  vector<int> t(n);
  rep(i, n) {
    scanf("%d", &t[i]);
    s.insert(t[i]);
  }

  if (s.size() == 1) {
    printf("1\n");
    rep(i, n) printf("1 ");
    printf("\n");
    return;
  }

  if (n % 2 == 0) {
    printf("2\n");
    rep(i, n) printf("%d ", i % 2 + 1);
    printf("\n");
    return;
  }

  int iEq = -1;
  rep(i, n) {
    if (t[i] == t[(i + 1) % n]) {
      iEq = i;
      break;
    };
  }
  if (iEq != -1) {
    printf("2\n");
    rep(i, n) printf("%d ", ((i + (i > iEq)) % 2 + 1));
    printf("\n");
    return;
  }

  printf("3\n");
  printf("3 ");
  rep(i, n - 1) printf("%d ", (i % 2 + 1));
  printf("\n");
}

int main() {
  int q;
  cin >> q;
  rep(i, q) solve();
  return 0;
}
