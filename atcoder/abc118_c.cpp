#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#include "../include/gcd.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = a[0];
  rep(i, n - 1) { ans = gcd(ans, a[i + 1]); }

  cout << ans << endl;

  return 0;
}
