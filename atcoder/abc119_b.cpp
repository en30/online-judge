#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;

  string s;
  double ans = 0;
  double v;

  rep(i,N) {
    cin >> v >> s;
    if(s == "JPY") {
      ans += v;
    } else {
      ans += 380000.0 * v;
    }
  }

  cout << ans << endl;
  return 0;
}
