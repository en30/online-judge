#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  int ans = 1;
  while((ans << 1) <= n) ans = (ans << 1);
  cout << ans << endl;
  return 0;
}
