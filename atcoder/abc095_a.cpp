#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string S;
  cin >> S;
  int ans = 700;
  for(char c: S) {
    if(c == 'o') ans += 100;
  }
  cout << ans << endl;
  return 0;
}
