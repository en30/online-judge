#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  int ans = 64;
  rep(i,n) {
    int a;
    int j = 0;
    cin >> a;
    while(a % 2 == 0) {
      a = (a >> 1);
      j++;
    }
    ans = min(ans, j);
  }
  cout << ans << endl;
  return 0;
}
