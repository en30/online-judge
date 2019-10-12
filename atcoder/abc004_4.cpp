#include <bits/stdc++.h>
#include "../include/template"

const int INF = 1e9;
int R, G, B;

// [l, r]
int sum(int l, int r) {
  if (l == 0) return r * (r + 1) / 2;
  if (l < 0) {
    if (r > 0) return sum(0, -l) + sum(0, r);
    return sum(-r, -l);
  }
  return sum(0, r) - sum(0, l - 1);
};

int cost(int x, int M, int base) { return sum(x - base, x + M - 1 - base); };

int main() {
  cin >> R >> G >> B;

  int ans = INF;

  for (int lG = -1000 - G; lG <= 1000; ++lG) {
    int c = 0;
    c += cost(lG, G, 0);
    c += cost(min(lG - R, -100 - R / 2), R, -100);
    c += cost(max(lG + G, 100 - B / 2), B, 100);
    ans = min(ans, c);
  }

  cout << ans << endl;

  return 0;
}
