#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string s, t;
int n;

bool ok() {
  for(int r = 0; r < n; r++) {
    bool yes = true;
    for(int i = 0; i < n; i++) {
      yes &= (s[(i+r)%n] == t[i]);
    }
    if(yes) return true;
  }
  return false;
}

int main () {
  cin >> s >> t;
  n = s.size();

  cout << (ok() ? "Yes" : "No") << endl;
  return 0;
}
