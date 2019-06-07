#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, q;
  string s;

  cin >> n >> q;
  cin >> s;

  vector<int> S(n+1, 0);
  for(int i = 2; i <= n; i++) {
    S[i] = (s[i-2] == 'A' && s[i-1] == 'C') ? S[i-1] + 1 : S[i-1];
  }

  int l,r, ans;
  rep(i,q) {
    cin >> l >> r;
    l--; r--;
    ans = S[r+1] - S[l];
    if(l > 0 && s[l] == 'C' && s[l-1] == 'A') ans--;
    cout << ans << endl;
  }

  return 0;
}
