#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;
struct Point {
  ll x, y;
};
vector<Point> points;

int main () {
  cin >> N >> K;
  points.resize(N);

  rep(i,N) cin >> points[i].x >> points[i].y;

  ll ans = 4e18+1;
  rep(i,N) for(int j = i; j < N; j++) for(int k = j; k < N; k++) for(int l = k; l < N; l++){
        ll xmin = min({points[i].x, points[j].x, points[k].x, points[l].x});
        ll xmax = max({points[i].x, points[j].x, points[k].x, points[l].x});
        ll ymin = min({points[i].y, points[j].y, points[k].y, points[l].y});
        ll ymax = max({points[i].y, points[j].y, points[k].y, points[l].y});
        int c = 0;
        for(auto &p: points) {
          if(p.x < xmin || p.x > xmax) continue;
          if(p.y < ymin || p.y > ymax) continue;
          c++;
        }
        if(c < K) continue;
        ans = min(ans, (xmax - xmin) * (ymax - ymin));
      }

  cout << ans << endl;

  return 0;
}
