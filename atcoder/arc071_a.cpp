#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int INF = 100;
int main () {
  vector<int> res(26, 100);
  int n;
  cin >> n;
  rep(i,n) {
    vector<int> c(26, 0);
    string s;
    cin >> s;
    rep(j,s.size()) {
      c[s[j] - 'a']++;
    }
    rep(j,26) res[j] = min(res[j], c[j]);
  }

  rep(i,26) {
    while(res[i] != 0) {
      printf("%c", char(i + 'a'));
      res[i]--;
    }
  }
  printf("\n");

  return 0;
}
