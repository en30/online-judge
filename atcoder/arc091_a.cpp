#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

ll N, M;
int main () {
  cin >> N >> M;

  ll ans = N * M;
  if(N == 1 && M == 1) {
  } else if (N == 1 || M == 1) {
    ans -= 2;
  } else {
    ans -= 2*N + 2*M - 4;
  }
  cout << ans << endl;
  return 0;
}
