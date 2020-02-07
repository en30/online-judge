#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  int ans = 0;
  int t = 10;
  rep(i, 9) {
    ans += (t / 10) * (N / t) + min(t / 10, max(N % t + 1 - t / 10, 0));
    t *= 10;
  }
  cout << ans << endl;
  
  return 0;
}
