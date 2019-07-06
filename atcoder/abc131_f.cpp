#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int G = 2e5;
vector<int> e[G+1];
bool used[G+1];

const int yBase = 1e5;

ll nx, ny;

void dfs(int u) {
  if(used[u]) return;
  used[u] = true;
  if(u <= yBase) {
    nx++;
  } else {
    ny++;
  }

  for(auto v: e[u]) dfs(v);
}

int main () {
  int N;
  cin >> N;

  rep(i,N) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(yBase+y);
    e[yBase+y].push_back(x);
  }

  ll ans = -N;
  for(int i = 1; i <= G; i++) {
    if(used[i]) continue;
    nx = ny = 0;
    dfs(i);
    ans += nx * ny;
  }

  cout << ans << endl;

  return 0;
}
