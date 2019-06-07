#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string s;

bool isOK(int l) {
  for(int i = 0; i < l; i++) {
    if(s[i] != s[i+l]) return false;
  }
  return true;
}

int main () {
  cin >> s;
  int res;
  for(int l = s.size() / 2 - 1; l >= 1; l--) {
    if(isOK(l)) {
      res = 2*l;
      break;
    }
  }

  cout << res << endl;
  return 0;
}
