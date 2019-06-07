#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, m;
  cin >> n >> m;

  vector<int> rem(m, 0);
  vector<int> c(m, 0);
  vector<queue<int>> q(n, queue<int>());
  int x;
  rep(i,n)rep(j,m) {
    cin >> x;
    q[i].push(x-1);
  }

  int ans = n;

  rep(k,m-1) {
    fill(c.begin(), c.end(), 0);
    rep(j,n) c[q[j].front()] += 1;
    int mi = 0;
    rep(i,m) if(c[i] > c[mi]) mi = i;
    ans = min(ans, c[mi]);
    rem[mi] = 1;
    rep(j,n) while(rem[q[j].front()]) q[j].pop();
  }

  cout << ans << endl;

  return 0;
}
