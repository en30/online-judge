#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

ll N;
vector<ll> A, B;

int main () {
  cin >> N;
  A.resize(N+1), B.resize(N);
  rep(i,N+1) cin >> A[i];
  rep(i,N) cin >> B[i];

  ll ans = 0;
  ll c = A[0];
  rep(i,N) {
    int d = min(c, B[i]);
    ans += d;
    B[i] -= d;
    c = A[i+1];
    if(B[i] > 0) {
      int d = min(c, B[i]);
      ans += d;
      c -= d;
    }
  }

  cout << ans << endl;

  return 0;
}
