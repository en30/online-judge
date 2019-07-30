#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

struct Station {
  int dist, start, T;
};
vector<Station> s;

int main () {
  cin >> N;
  s.resize(N-1);

  rep(i,N-1) cin >> s[i].dist >> s[i].start >> s[i].T;

  rep(i,N-1) {
    int t = 0;
    for(int j = i; j < N - 1; j++) {
      t = max(((t + s[j].T - 1) / s[j].T) * s[j].T, s[j].start) + s[j].dist;
    }
    cout << t << endl;
  }
  cout << 0 << endl;

  return 0;
}
