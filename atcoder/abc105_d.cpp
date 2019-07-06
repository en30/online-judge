#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, M;
  cin >> N >> M;

  vector<int> S(N+1, 0);
  rep(i,N) {
    int a;
    cin >> a;
    S[i+1] = (S[i] + a) % M;
  }

  ll ans = 0;
  map<int, int> m;
  for(int i = 0; i <= N; i++) {
    ans += m[(M+S[i])%M];
    m[S[i]]++;
  }

  cout << ans << endl;

  return 0;
}
