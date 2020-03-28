#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"
#include "../include/re_rooting.hpp"

struct State {
  int c;
  ModInt m;
  bool operator!=(const State& that) { return c != that.c || m != that.m; }
};

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  Combination<ModInt> comb(N);

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  ReRooting<State, State> rr(
      G,
      [&](State a, State e) {
        return State{a.c + e.c, a.m * e.m / comb.factorial(e.c)};
      },
      [&](int i, State lp, State rp) {
        return State{lp.c + rp.c + 1,
                     lp.m * rp.m * comb.factorial(lp.c + rp.c)};
      },
      [](int i) {
        return State{0, 1};
      },
      State{-1, 0});

  rep(i, N) cout << rr.value(i, -1).m << endl;

  return 0;
}
