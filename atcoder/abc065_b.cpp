#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int INFTY = 1000000;
int main () {
  int n;
  cin >> n;
  vector<int> d(n, INFTY);
  vector<vector<int>> al(n+1);
  rep(i,n) {
    int a;
    cin >> a;
    al[i].push_back(a-1);
  }

  queue<int> q;
  q.push(0);
  d[0] = 0;
  int u;
  while(!q.empty()) {
    u = q.front(); q.pop();
    for(int j : al[u]) {
      if(d[j] != INFTY)  continue;
      d[j] = d[u] + 1;
      q.push(j);
    }
  }

  printf("%d\n", d[1] == INFTY ? -1 : d[1]);
  return 0;
}
