#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B , C, X, Y;
int main () {
  cin >> A >> B >> C >> X >> Y;
  int ans = 1e9;
  for(int i = 0; i/2 <= max(X,Y); i += 2) {
    int x = X - i / 2;
    int y = Y - i / 2;
    int p = i * C + max(x,0) * A + max(y,0) * B;
    ans = min(ans, p);
  }
  cout << ans << endl;

  return 0;
}
