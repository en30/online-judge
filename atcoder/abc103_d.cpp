#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct war {
  int a, b;
};

int main () {
  int N, M;
  cin >> N >> M;
  vector<war> wars(M);
  rep(i,M) cin >> wars[i].a >> wars[i].b;


  sort(wars.begin(), wars.end(), [](const war&a, const war&b) { return a.a < b.a; });

  int l = 0, r = 1e9;
  int ans = 1;
  rep(i,M) {
    if(wars[i].a >= r) {
      ans += 1;
      l = wars[i].a;
      r = wars[i].b;
    } else {
      l = wars[i].a;
      r = min(r, wars[i].b);
    }
  }

  cout << ans << endl;

  return 0;
}
