#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int X, Y, Z;

int main () {
  cin >> X >> Y >> Z;

  int ans = X / (Z+Y);
  if(X % (Z+Y) < Z) ans--;
  cout << ans << endl;
  return 0;
}
