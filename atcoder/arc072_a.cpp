#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n)cin >> a[i];

  ll c1 = 0, c2 = 0;
  ll s1 = 0, s2 = 0;
  for(int i = 0; i < n; i++) {
    s1 += a[i];
    if(i % 2 == 0 && s1 <= 0) {
      c1 += -s1 + 1;
      s1 = 1;
    } else if(i % 2 == 1 && s1 >= 0) {
      c1 += s1 + 1;
      s1 = -1;
    }

    s2 += a[i];
    if(i % 2 == 1 && s2 <= 0) {
      c2 += -s2 + 1;
      s2 = 1;
    } else if(i % 2 == 0 && s2 >= 0) {
      c2 += s2 + 1;
      s2 = -1;
    }
  }

  cout << min(c1, c2) << endl;
  return 0;
}
