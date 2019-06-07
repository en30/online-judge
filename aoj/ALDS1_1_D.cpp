#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, r;
  int m = -1;
  int res = - 1e9;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> r;
    if(i == 0) {
      m = r;
      continue;
    }
    res = max(res, r - m);
    m = min(r, m);
  }
  cout << res << endl;
  return 0;
}
