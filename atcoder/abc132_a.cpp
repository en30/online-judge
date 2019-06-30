#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string s;
bool ok() {
  if(s[0] == s[1] && s[2] == s[3] && s[1] != s[2]) return true;
  if(s[0] == s[2] && s[1] == s[3] && s[1] != s[2]) return true;
  if(s[0] == s[3] && s[1] == s[2] && s[3] != s[1]) return true;
  return false;
}

int main () {
  cin >> s;
  cout << (ok() ? "Yes" : "No") << endl;

  return 0;
}
