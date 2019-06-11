#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, M;
  cin >> N >> M;

  int ans = 1;
  for(int i = sqrt(M); i >= 1; i--) {
    if(M % i) continue;
    if(M / i >= N) ans = max(ans, i);
    if(i >= N) ans = max(ans, M/i);
  }

  cout << ans << endl;
  return 0;
}
