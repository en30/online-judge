#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

ll N;
vector<int> S, a;

ll merge(int l, int m, int r) {
  int i, j, k;
  ll cnt = 0;
  int n1 = m - l;
  int n2 = r - m;
  vector<int> L(n1+1), R(n2+1);
  rep(i,n1) L[i] = S[l+i];
  rep(i,n2) R[i] = S[m+i];
  L[n1] = R[n2] = 1e9+1;
  i = j = 0;
  for(k = l; k < r; k++) {
    if(L[i] <= R[j]) {
      S[k] = L[i++];
      cnt += n2 - j;
    } else {
      S[k] = R[j++];
    }
  }
  return cnt;
}

ll count(int l, int r) {
  if(r - l <= 1) return 0;

  int m;
  ll v1, v2, v3;
  m = (l + r) / 2;
  v1 = count(l, m);
  v2 = count(m, r);
  v3 = merge(l, m, r);
  return v1 + v2 + v3;
}

int main () {
  cin >> N;
  a = vector<int>(N);
  S = vector<int>(N+1);
  rep(i,N) cin >> a[i];

  // [l, r)
  int l = 0, r = 1e9 + 1;
  ll t = (N*(N+1)/2 + 1)/2;
  while(r - l > 1) {
    int x = (l + r) / 2;
    S[0] = 0;
    rep(i,N) S[i+1] = S[i] + (a[i] >= x ? 1 : -1);
    if(count(0, N+1) >= t) {
      l = x;
    } else {
      r = x;
    }
  }

  cout << l << endl;

  return 0;
}
