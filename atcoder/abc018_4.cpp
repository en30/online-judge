#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"

struct Choco {
  int from, to, happiness;
};

int main() {
  int N, M, P, Q, R;
  cin >> N >> M >> P >> Q >> R;

  vector<Choco> C(R);
  rep(i, R) {
    cin >> C[i].from >> C[i].to >> C[i].happiness;
    C[i].from--;
    C[i].to--;
  }

  ll ans = 0;
  int sp = first_fixed_size_set(P);
  do {
    vector<int> s(M, 0);
    rep(i, R) {
      if ((sp >> C[i].from) & 1) s[C[i].to] += C[i].happiness;
    }
    sort(s.rbegin(), s.rend());
    ans = max(ans, accumulate(s.begin(), s.begin() + Q, 0LL));
  } while (next_fixed_size_set(N, P, sp));

  cout << ans << endl;

  return 0;
}
