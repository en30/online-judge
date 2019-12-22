#include <bits/stdc++.h>
#include "../include/template"

ll N;

ll f(ll n, int k) {
  if (n / k == 0) return 0;
  return n / k + f(n / k, k);
}

int main() {
  cin >> N;

  if (N % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  cout << min(f(N / 2, 2) + N / 2, f(N / 2, 5)) << endl;

  return 0;
}
