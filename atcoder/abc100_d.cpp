#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, M;

struct cake {
  ll x,y,z;

  ll ord(const int s) const {
    ll v = (s & 1) ? x : -x;
    v += ((s >> 1) & 1) ? y : -y;
    v += ((s >> 2) & 1) ? z : -z;
    return v;
  }

  ll val() const {
    return abs(x) + abs(y) + abs(z);
  }

  const cake operator+(const cake& rhs) const {
    return cake{x+rhs.x, y+rhs.y, z+rhs.z};
  }
};

vector<cake> cakes;

int main () {
  cin >> N >> M;
  cakes.resize(N);
  rep(i,N) cin >> cakes[i].x >> cakes[i].y >> cakes[i].z;

  ll ans = 0;
  for(int s = 0; s < 8; s++) {
    sort(cakes.begin(), cakes.end(), [&s](const cake &a, const cake &b) {
        return a.ord(s) > b.ord(s);
      });
    cake c = cake{0,0,0};
    rep(i,M) c = c + cakes[i];
    ans = max(ans, c.val());
  }

  cout << ans << endl;

  return 0;
}
