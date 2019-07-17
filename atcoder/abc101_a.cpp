#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  int ans = 0;
  cin >> s;
  for(char c: s) {
    if(c == '+') {
      ans++;
    } else {
      ans--;
    }
  }
    cout << ans << endl;
  return 0;
}
