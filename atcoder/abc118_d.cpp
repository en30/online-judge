#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int n, m;
int c[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

const int INF = 1e9;

int main () {
  cin >> n >> m;

  vector<int> a(m);
  rep(i,m) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());

  vector<int> dMax(n+1, -INF);
  dMax[0] = 0;

  for(int i = 1; i <= n; i++) {
    rep(j,m) {
      if(i >= c[a[j]]) dMax[i] = max(dMax[i], dMax[i-c[a[j]]] + 1);
    }
  }

  int rest = n;
  rep(i,m) {
    while(rest - c[a[i]] >= 0 && dMax[rest - c[a[i]]] == dMax[rest] - 1) {
      cout << a[i];
      rest -= c[a[i]];
    }
  }
  cout << endl;

  return 0;
}
