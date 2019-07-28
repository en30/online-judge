#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string s, t;
int n, m;
const int R = 256;
const int INF = 1e9;
vector<vector<int>> dfa;
vector<int> match;
vector<int> L;

void kmp() {
  dfa.resize(R, vector<int>(m+1));
  dfa[t[0]][0] = 1;
  for(int x = 0, j = 1; j <= m; j++) {
    for(int c = 0; c < R; c++) {
      dfa[c][j] = dfa[c][x];
    }
    dfa[t[j]][j] = (j+1)%(m+1);
    x = dfa[t[j]][x];
  }
}

vector<int> used;
int pathLength(int i) {
  if(!match[i]) return 0;
  if(L[i] != -1) return L[i];
  if(used[i]) return INF;

  used[i] = 1;
  return L[i] = min(INF, pathLength((i+m)%n) + 1);
}

int main () {
  cin >> s >> t;
  n = s.size(), m = t.size();
  match.resize(n);
  L.resize(n, -1);

  kmp();
  for(int i = 0, j = 0; i < n + m - 1; i++) {
    j = dfa[s[i%n]][j];
    if(j == m) match[i-m+1] = 1;
  }

  used.resize(n, 0);
  int ans = 0;
  rep(i,n) {
    if(match[i]) ans = max(ans, pathLength(i));
  }

  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
