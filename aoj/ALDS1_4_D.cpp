#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

bool query(ll p, int k, vector<int> &w) {
  ll cw = 0;
  int m = 1;
  for(int i = 0; i < w.size(); i++) {
    if(w[i] > p) return false;
    if(cw + w[i] > p) {
      if(cw > 0) m++;
      cw = 0;
    }
    cw += w[i];
  }
  return m != 0 && m <= k;
}

int search(ll il, ll ir, int k, vector<int> &w) {
  ll l = il, r = ir;
  while(r - l > 1) {
    ll m = (l + r) / 2;
    if(query(m, k, w)) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}

int main () {
  int n, k;
  cin >> n >> k;
  vector<int> w(n);
  rep(i,n) cin >> w[i];
  cout << search(0, 1e9, k, w) << endl;
  return 0;
}
