#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, q;

  cin >> n;
  vector<int> S(n+1);
  rep(i,n) cin >> S[i];

  cin >> q;
  vector<int> T(q);
  rep(i,q) cin >> T[i];

  int ans = 0;
  rep(i,q) {
    int j = 0;
    S[n] = T[i];
    while(S[j] != T[i]) j++;
    if(j != n) ans++;
  }
  cout << ans << endl;
  return 0;
}
