#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  sort(h.begin(), h.end());

  int ans = 1e9;
  for(int i = 0; i <= n - k; i++) {
    ans = min(ans, h[i+k-1] - h[i]);
  }

  cout << ans << endl;
  return 0;
}
