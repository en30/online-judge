#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int S = 0;
const int W = 1;

int sim(vector<int> &p, int n, string &s) {
  for(int i = 1; i < n; i++) {
    int ni = (i + 1) % n;
    if((p[i] == S && s[i] == 'o') || (p[i] == W && s[i] == 'x')) {
      if(p[ni] != -1 && p[ni] != p[i-1]) return 0;
      p[ni] = p[i-1];
    } else {
      if(p[ni] != -1 && p[ni] != !p[i-1]) return 0;
      p[ni] = !p[i-1];
    }
  }
  return 1;
}

int main () {
  int n;
  string s;
  cin >> n >> s;

  vector<vector<int>> p(4, vector<int>(n, -1));
  rep(i,4) {
    p[i][0] = i&1;
    p[i][1] = (i>>1)&1;
    p[i][n-1] = ((p[i][0] == S && s[0] == 'o') || (p[i][0] == W && s[0] == 'x')) ? p[i][1] : !p[i][1];
    if(sim(p[i], n, s)) {
      rep(j,n) cout << (p[i][j] ? 'W' : 'S');
      cout << endl;
      return 0;
    }
  }
  cout << "-1" << endl;

  return 0;
}
