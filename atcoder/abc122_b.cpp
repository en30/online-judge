#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

bool isACGT(char c) {
  return c == 'A' || c == 'C' || c == 'G' || c == 'T';
}

int main () {
  string s;
  cin >> s;

  int cnt = 0;
  int ans = 0;
  for(int i = 0, l = s.size(); i < l;) {
    cnt = 0;
    while(i < l && isACGT(s[i])) {
      cnt++;
      i++;
    }
    ans = max(ans, cnt);
    while(i < l && !isACGT(s[i])) i++;
  }
  cout << ans << endl;
  return 0;
}
