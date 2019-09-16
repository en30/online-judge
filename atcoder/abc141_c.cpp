#include <bits/stdc++.h>
#include "../include/template"

int N, K, Q;
vector<int> p;

int main() {
  cin >> N >> K >> Q;
  p.resize(N, 0);
  rep(i, Q) {
    int A;
    cin >> A;
    p[A - 1]++;
  }

  rep(i, N) { cout << ((K - (Q - p[i])) > 0 ? "Yes" : "No") << endl; }
  return 0;
}
