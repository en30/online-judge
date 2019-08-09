#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, C;

int main () {
  cin >> N >> C;

  vector<int> s(N), t(N), c(N);
  rep(i,N) {
    cin >> s[i] >> t[i] >> c[i];
    c[i]--;
  }
  int T = 2 * (*max_element(all(t)));
  vector<int> sm(T+1, 0);
  rep(k,C) {
    vector<int> tt(T+1, 0);
    rep(i,N) if(c[i] == k) tt[s[i]*2-1]++, tt[t[i]*2]--;
    rep(t,T) tt[t+1] += tt[t];
    rep(t,T+1) sm[t] += min(tt[t], 1);
  }

  cout << *max_element(all(sm)) << endl;

  return 0;
}
