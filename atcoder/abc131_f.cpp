#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int G = 2e5;
vector<int> e[G+1];
bool used[G+1];

const int yBase = 1e5;

int main () {
  int N;
  cin >> N;

  rep(i,N) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(yBase+y);
    e[yBase+y].push_back(x);
  }

  ll ans = 0;
  queue<int> q;
  for(int i = 1; i <= G; i++) {
    if(used[i]) continue;

    ll nx, ny, ne;
    nx = ny = ne = 0;
    q.push(i);
    used[i] = true;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u <= yBase) {
        nx++;
      } else {
        ny++;
      }

      for(auto v: e[u]) {
        ne++;
        if(used[v]) continue;
        q.push(v);
        used[v] = true;
      }
    }
    if(nx >= 2 && ny >= 2) ans += nx * ny - ne/2;
  }

  cout << ans << endl;

  return 0;
}
