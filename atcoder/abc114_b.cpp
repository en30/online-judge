#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  cin >> s;
  int ans = 10000;
  for(int i = 0; i <= s.size() - 3; i++) {
    ans = min(ans, abs(753-stoi(s.substr(i, 3))));
  }
  cout << ans << endl;
  return 0;
}
