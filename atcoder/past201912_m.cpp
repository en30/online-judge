#include <bits/stdc++.h>
#include "../include/template"

int N, M;

struct Monster {
  ll A, B;
  bool helper;
};

int main() {
  cin >> N >> M;

  vector<Monster> MON(N + M);
  rep(i, N) {
    cin >> MON[i].A >> MON[i].B;
    MON[i].helper = false;
  }
  rep(i, M) {
    cin >> MON[i + N].A >> MON[i + N].B;
    MON[i + N].helper = true;
  }

  auto achievable = [&](double t) {
    sort(MON.rbegin(), MON.rend(), [&](const Monster& a, const Monster& b) {
      return (a.B - t * a.A) < (b.B - t * b.A);
    });

    int c = 0;
    double x = 0;
    bool helperUsed = false;
    rep(i, N + M) {
      if (helperUsed && MON[i].helper) continue;
      x += MON[i].B - t * MON[i].A;
      helperUsed |= MON[i].helper;
      c++;
      if (c >= 5) break;
    }
    return x >= 0;
  };

  double l = 0, r = 1e6;
  rep(i, 100) {
    double m = (l + r) / 2;
    if (achievable(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << setprecision(7) << l << endl;
  return 0;
}
