#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

struct Point {
  int x, y;
};

int N;
vector<Point> P;

using mint = ModInt;

template <typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }

  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
};

int main() {
  ModInt::mod(998244353);
  cin >> N;
  P.resize(N);

  rep(i, N) { cin >> P[i].x >> P[i].y; }

  {
    map<int, int> m;
    rep(i, N) m[P[i].x] = 0;
    int i = 0;
    for (auto &&x : m) x.second = i++;
    rep(i, N) P[i].x = m[P[i].x];
  }
  {
    map<int, int> m;
    rep(i, N) m[P[i].y] = 0;
    int i = 0;
    for (auto &&x : m) x.second = i++;
    rep(i, N) P[i].y = m[P[i].y];
  }

  mint ans = 0;
  mint two = 2;
  vector<vector<ll>> c(N, vector<ll>(4));
  sort(all(P), [&](const Point &a, const Point &b) { return a.x < b.x; });

  {
    BIT<int> bit(N);
    rep(i, N) {
      c[i][2] = bit.sum(P[i].y);
      c[i][1] = i - c[i][2];
      bit.add(P[i].y);
    }
  }
  {
    BIT<int> bit(N);
    for (int i = N - 1; i >= 0; i--) {
      c[i][3] = bit.sum(P[i].y);
      c[i][0] = N - 1 - i - c[i][3];
      bit.add(P[i].y);
    }
  }

  vector<mint> o(4), ox(4);
  rep(i, N) {
    rep(j, 4) {
      ox[j] = two.pow(c[i][j]);
      o[j] = ox[j] - 1;
    }
    ans += ox[0] * ox[1] * ox[2] * ox[3];
    ans += o[0] * ox[1] * o[2] * ox[3];
    ans += ox[0] * o[1] * ox[2] * o[3];
    ans -= o[0] * o[1] * o[2] * o[3];
  }

  cout << ans << endl;

  return 0;
}
