#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;

  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
    A[i] -= i + 1;
  }
  sort(A.begin(), A.end());

  vector<ll> S(N+1, 0);
  rep(i,N) S[i+1] = S[i] + A[i];

  ll ans = -1;
  for(int i = 0; i < N; i++) {
    ll T = S[N] - 2*S[i] + (2*i - N)*A[i];
    if(ans == -1) ans = T;
    ans = min(ans, T);
  }

  cout << ans << endl;

  return 0;
}
