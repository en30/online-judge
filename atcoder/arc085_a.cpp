#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int N, M;
  cin >> N >> M;

  int ans = 1900*M + 100*(N-M);
  rep(i,M) ans *= 2;
  cout << ans << endl;

  return 0;
}
