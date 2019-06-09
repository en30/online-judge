#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)


struct city {
  int index, id, p, y;
};


int main () {
  int n, m;

  cin >> n >> m;
  vector<city> c(m);

  rep(i,m) {
    cin >> c[i].p >> c[i].y;
    c[i].index = i;
  }

  sort(c.begin(), c.end(), [](const city&a, const city&b) {
      return a.p == b.p ? a.y < b.y : a.p < b.p;
    });

  int cp = -1;
  int ci;
  rep(i,m) {
    if(cp != c[i].p) {
      cp = c[i].p;
      ci = 1;
    } else {
      ci++;
    }
    c[i].id = ci;
  }

  sort(c.begin(), c.end(), [](const city&a, const city&b) {
      return a.index < b.index;
    });

  rep(i,m) {
    printf("%06d%06d\n", c[i].p, c[i].id);
  }

  return 0;
}
