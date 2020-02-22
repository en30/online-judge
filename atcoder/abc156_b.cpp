#include <bits/stdc++.h>
#include "../include/template"

int f(int n, int k) {
  if (n == 0) return 0;
  return 1 + f(n / k, k);
}

int main() {
  int N, K;
  cin >> N >> K;
  cout << f(N, K) << endl;
  return 0;
}
