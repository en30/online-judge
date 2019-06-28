#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  rep(i,N) cin >> x[i];

  int ans = 1e9;

  for(int i = 0; i + K - 1 < N; i++) {
    int l = x[i];
    int r = x[i+K-1];
    if(r <= 0) {
      ans = min(ans, -l);
    } else if(l >= 0) {
      ans = min(ans, r);
    } else {
      ans = min(ans, min(abs(l), abs(r)) * 2 + max(abs(l), abs(r)));
    }
  }

  cout << ans << endl;
  return 0;
}
