#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  cin >> s;
  rep(i, s.size()) {
    if(i % 2 == 0) cout << s[i];
  }
  cout << endl;
  return 0;
}
