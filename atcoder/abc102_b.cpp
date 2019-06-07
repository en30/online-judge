#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  int mi = 1e9 + 1, ma = 0;
  cin >> n;
  rep(i,n) {
    int a;
    cin >> a;
    mi = min(a, mi);
    ma = max(a, ma);
  }
  cout << ma - mi << endl;
  return 0;
}
