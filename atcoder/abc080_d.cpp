#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, C;

struct Show {
  int s, t, c;

  bool operator < (const Show& that) {
    return s < that.s;
  }
};

int main () {
  cin >> N >> C;

  vector<vector<Show>> ss(C);
  rep(i,N) {
    Show x;
    cin >> x.s >> x.t >> x.c;
    x.c--;
    ss[x.c].push_back(x);
  }

  vector<Show> shows;
  rep(i,C) {
    sort(all(ss[i]));
    int l = ss[i].size();
    rep(j,l) {
      while(j + 1 < l && ss[i][j].t == ss[i][j+1].s) {
        ss[i][j+1].s = ss[i][j].s;
        j++;
      }
      shows.push_back(ss[i][j]);
    }
  }

  int ans = 1;
  priority_queue<int, vector<int>, greater<int>> pq;
  sort(all(shows));
  for(auto& s: shows) {
    while(!pq.empty() && pq.top() < s.s) pq.pop();
    ans = max(ans, static_cast<int>(pq.size()) + 1);
    pq.push(s.t);
  }

  cout << ans << endl;

  return 0;
}
