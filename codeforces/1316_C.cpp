#include <bits/stdc++.h>
#include "../include/template"

int a[1010101], b[1010101];

int main() {
  int n, m, p;
  cin >> n >> m >> p;
  rep(i, n) {
    scanf("%d", &a[i]);
    a[i] %= p;
  }
  rep(i, m) {
    scanf("%d", &b[i]);
    b[i] %= p;
  }
  12.cpp

  rep(i, n) {
    if (a[i] != 0) {
      rep(j, m) {
        if (b[j] != 0) {
          cout << i + j << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}
