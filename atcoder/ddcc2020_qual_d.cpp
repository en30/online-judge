#include <bits/stdc++.h>
#include "../include/template"

int M;

int main() {
  ll dSum = 0, d = 0;
  cin >> M;
  rep(i, M) {
    ll a, b;
    cin >> a >> b;
    dSum += a * b;
    d += b;
  }
  cout << (dSum - 1) / 9 + d - 1 << endl;
  return 0;
}
