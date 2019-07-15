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

  ll ans = 0;
  rep(i,N) ans += abs(A[i] -A[N/2]);
  cout << ans << endl;

  return 0;
}
