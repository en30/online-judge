#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

ll N, K;

int main () {
  cin >> N >> K;

  if(K == 0) {
    cout << N*N << endl;
    return 0;
  }

  ll ans = 0;
  for(ll b = K+1; b <= N; b++) {
    ans += (N/b)*(b-K) + max(0LL, N % b - K + 1);
  }
  cout << ans << endl;
  return 0;
}
