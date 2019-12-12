#include <bits/stdc++.h>
#include "../include/template"
#include "../include/matrix.hpp"
#include "../include/mod.hpp"

ll L, A, B, M;

ll p(ll x, ll r) {
  if (r == 0) return 1;
  ll res = 1;
  if (r % 2 != 0) res = x;
  ll y = p(x, r / 2);
  return y * y * res;
}

struct Pos {
  // 10^r >= s[j] for j in [i,
  ll i, r;
};

int main() {
  cin >> L >> A >> B >> M;

  ModInt::mod(M);
  using mint = ModInt;

  vector<Pos> t;
  {
    t.push_back(Pos{0, (ll)log10(A)});
    ll k = t[0].r + 1, th = p(10, k);
    while (A + (L - 1) * B >= th) {
      ll l = 0, r = L - 1;
      while (r - l > 1) {
        ll m = (l + r) / 2;
        if (A + m * B < th) {
          l = m;
        } else {
          r = m;
        }
      }
      t.push_back(Pos{r, k});
      ++k;
      th *= 10;
    }
    t.push_back(Pos{L, -1});
  }

  Matrix<mint> res = {{0}, {A}, {1}};

  rep(i, t.size() - 1) {
    Matrix<mint> r = {{p(10, t[i].r + 1), 1, 0}, {0, 1, B}, {0, 0, 1}};
    res = r.power(t[i + 1].i - t[i].i) * res;
  }

  cout << res[0][0] << endl;
  return 0;
}
