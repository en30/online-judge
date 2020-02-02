#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  rep(i, N) {
    int a;
    cin >> a;
    if (a == 1) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
