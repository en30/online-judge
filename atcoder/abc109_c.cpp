#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#include "../include/gcd.hpp"

int main() {
  int N, X, ans;

  cin >> N >> X;

  ans = 0;
  rep(i, N) {
    int x;
    cin >> x;
    ans = gcd(abs(x - X), ans);
  }

  cout << ans << endl;
  return 0;
}
