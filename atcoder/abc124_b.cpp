#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int m = h[0];
  int c = 0;

  rep(i,n) {
    if(h[i] >= m) {
      m = max(m, h[i]);
      c++;
    }
  }

  cout << c << endl;
  return 0;
}
