#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll N, A, B;
  cin >> N >> A >> B;

  ll r = N / (A + B);
  ll rest = N - r * (A + B);
  cout << r * A + min(rest, A) << endl;
  return 0;
}
