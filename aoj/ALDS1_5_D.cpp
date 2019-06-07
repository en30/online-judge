#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int INFTY = 1e9+1;

ll merge(vector<int> &a, int l, int m, int r) {
  int nl = m - l;
  int nr = r - m;
  vector<int> L(nl+1);
  vector<int> R(nr+1);
  rep(i,nl) L[i] = a[l+i];
  rep(i,nr) R[i] = a[m+i];
  L[nl] = INFTY;
  R[nr] = INFTY;
  int i = 0;
  int j = 0;
  ll c = 0;
  while(i + j < r - l) {
    if(L[i] <= R[j]) {
      a[l+i+j] = L[i];
      i++;
    } else {
      a[l+i+j] = R[j];
      c += nl - i;
      j++;
    }
  }
  return c;
}

ll numberOfInversions(vector<int> &a, int l, int r) {
  if(r - l <= 1) return 0;
  int m = (r + l) / 2;
  ll cl = numberOfInversions(a, l, m);
  ll cr = numberOfInversions(a, m, r);
  ll cm = merge(a, l, m, r);
  return cl + cr + cm;
}

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  cout << numberOfInversions(a, 0, n) << endl;
  return 0;
 }
