#include <bits/stdc++.h>
#include "../include/template"

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int N;
vector<ll> T;
int main() {
  cin >> N;
  T.resize(N);
  rep(i, N) cin >> T[i];

  ll g = 1, ans = 1;
  rep(i, N) {
    g = gcd(ans, T[i]);
    ans = ans * (T[i] / g);
  }
  cout << ans << endl;
  return 0;
}
