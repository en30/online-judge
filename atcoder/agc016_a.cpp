#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  cin >> s;

  int ans = 1000;
  int n = s.size();
  for(char c = 'a'; c <= 'z'; c++) {
    int pi = -1;
    int res = -1;
    for(int i = 0; i < n; i++) {
      if(s[i] == c) {
        res = max(res, i - pi - 1);
        pi = i;
      }
    }
    res = max(res, n - pi - 1);

    if(res != -1) ans = min(ans, res);
  }

  cout << ans << endl;

  return 0;
}
