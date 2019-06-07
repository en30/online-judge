#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int n;
int s[100];

int main () {
  int res = 0;
  cin >> n;
  rep(i,n) {
    cin >> s[i];
    res += s[i];
  }

  sort(s, s + n);
  for(int i = 0; i < n && res % 10 == 0; i++) {
    if(s[i] % 10 != 0) {
      res -= s[i];
    }
  }
  if(res % 10 == 0) res = 0;

  cout << res << endl;
  return 0;
}
