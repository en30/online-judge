#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  cout << (N <= K ? N * X : K * X + (N - K) * Y) << endl;
  return 0;
}
