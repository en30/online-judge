#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct elm {
  int v, c;
};

int main () {
  int n;
  cin >> n;
  vector<elm> a(1e5+1), b(1e5+1);
  rep(i,1e5+1) {
    a[i] = elm{i,0};
    b[i] = elm{i,0};
  }

  rep(i,n/2) {
    int x, y;
    cin >> x >> y;
    a[x].c++;
    b[y].c++;
  }

  sort(a.begin(), a.end(), [](const elm& l, const elm& r ) {
      return l.c > r.c;
    });
  sort(b.begin(), b.end(), [](const elm& l, const elm& r ) {
      return l.c > r.c;
    });

  if(a[0].v != b[0].v) {
    cout << n - a[0].c - b[0].c << endl;
  } else {
    int ans = 1e5+1;
    ans = min(ans, n - a[0].c - b[1].c);
    ans = min(ans, n - a[1].c - b[0].c);
    cout << ans << endl;
  }
  return 0;
}
