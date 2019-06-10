#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct city {
  int p, y;
};

bool operator<(const city& a, const int y) { return a.y < y; }

int main () {
  int n, m;

  cin >> n >> m;
  vector<city> c(m);
  vector<vector<city>> pc(n+1);

  rep(i,m)  {
    cin >> c[i].p >> c[i].y;
    pc[c[i].p].push_back(c[i]);
  }

  rep(i,n+1) sort(pc[i].begin(), pc[i].end(), [](const city&a, const city&b) {
      return a.y < b.y;
    });

  rep(i,m) {
    int id = lower_bound(pc[c[i].p].begin(), pc[c[i].p].end(), c[i].y) - pc[c[i].p].begin() + 1;
    printf("%06d%06d\n", c[i].p, id);
  }

  return 0;
}
