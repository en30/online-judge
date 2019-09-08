#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C, D, E, F;
int main() {
  cin >> A >> B >> C >> D >> E >> F;

  pair<int, int> ans;
  double c = -1;
  for (int x = 0; 100 * A * x <= F; ++x) {
    for (int y = 0; 100 * A * x + 100 * B * y <= F; ++y) {
      int a = 100 * A * x + 100 * B * y;
      for (int s = 0; C * s * 100 <= E * a && a + C * s <= F; ++s) {
        for (int t = 0;
             a + C * s + D * t <= F && 100 * (C * s + D * t) <= E * a; ++t) {
          int b = C * s + D * t;
          double cc = double(100) * b / (a + b);
          if (cc > c) {
            ans = make_pair(a + b, b);
            c = cc;
          }
        }
      }
    }
  }

  cout << ans.first << " " << ans.second << endl;
  return 0;
}
