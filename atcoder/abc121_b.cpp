#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i,m) cin >> b[i];

  int res = 0;
  rep(i,n) {
    int sum = c;
    rep(j,m) {
      int a;
      cin >> a;
      sum += a*b[j];
    }
    if(sum > 0) res += 1;
  }

  cout << res << endl;

  return 0;
}
