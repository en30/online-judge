#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> A, B, C;

int main () {
  cin >> N;
  A.resize(N), B.resize(N), C.resize(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N) cin >> C[i];

  sort(all(A)), sort(all(B)), sort(all(C));

  vector<ll> BC(N, 0);
  rep(i,N) {
    BC[i] = distance(upper_bound(all(C), B[i]), C.end());
  }
  for(int i = N-1; i > 0; --i) {
    BC[i-1] += BC[i];
  }

  ll ans = 0;
  rep(i,N) {
    int j = distance( B.begin(), upper_bound(all(B), A[i]));
    if(j < N) ans += BC[j];
  }

  cout << ans << endl;

  return 0;
}
