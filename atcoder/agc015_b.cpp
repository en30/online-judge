#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  ll res = 0;
  string s;
  int r = 0;
  cin >> s;
  int l = s.size();

  for(char c: s) {
    res += l - 1;
    res += c == 'U' ? r : (l - 1 - r);
    r++;
  }
  cout << res << endl;
  return 0;
}
