#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int D = 20;

int N;
vector<vector<ll>> S;

// [l, r]
bool good(int l, int r) {
  rep(d,D) {
    if(S[r+1][d] - S[l][d] > 1) return false;
  }
  return true;
}

int main () {
  cin >> N;

  S.resize(N+1, vector<ll>(D, 0));

  rep(i,N) {
    int A;
    cin >> A;
    rep(d,D) {
      S[i+1][d] = S[i][d] + ((A>>d)&1);
    }
  }

  ll ans = 0;
  for(int i = 0; i < N; i++) {
    int l = i, r = N;
    while(r - l > 1) {
      int m = (l+r)/2;
      if(good(i,m)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans += l - i + 1;
  }

  cout << ans << endl;

  return 0;
}
