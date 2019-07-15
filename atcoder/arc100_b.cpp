#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

typedef pair<ll, ll> res;

int N;
vector<ll> A, S;

// [l, r)
res minimize(int l0, int r0) {
  ll s = S[r0] - S[l0];
  int l = l0, r = r0;
  while(r - l > 1) {
    int m = (l+r)/2;
    if(S[m+1] - S[l0] <= s/2) {
      l = m;
    } else {
      r = m;
    }
  }
  if(r0 > l + 2 && abs(2*S[l+1]- S[l0] - S[r0]) > abs(2*S[l+2]- S[l0] - S[r0])) l++;
  ll x = S[l+1] - S[l0];
  ll y = S[r0] - S[l+1];
  return res(min(x,y), max(x,y));
}

int main () {
  cin >> N;

  A.resize(N), S.resize(N+1, 0);
  rep(i,N) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }

  ll ans = 1e15;
  res rl, rr;
  for(int i = 1; i < N-2; i++) {
    rl = minimize(0, i+1);
    rr = minimize(i+1, N);
    ans = min(ans, max(rl.second, rr.second) - min(rl.first, rr.first));
  }

  cout << ans << endl;
  return 0;
}
