#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()


int main () {
  int N;
  cin >> N;
  int pt = 0, px = 0, py = 0;
  rep(i,N) {
    int t, x, y;
    cin >> t >> x >> y;
    int dt = t - pt;
    int d = abs(x-px) + abs(y-py);
    if(d > dt || (dt % 2 != d %2)) {
      cout << "No" << endl;
      return 0;
    }
    pt = t, px = x, py = y;
  }
  cout << "Yes" << endl;
  return 0;
}
