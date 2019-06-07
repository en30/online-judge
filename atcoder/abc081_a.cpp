#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  char c;
  int ans = 0;
  rep(i,3) {
    cin >> c;
    if(c == '1') ans++;
  }
  cout << ans << endl;
  return 0;
}
