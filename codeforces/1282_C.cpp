#include <bits/stdc++.h>
#include "../include/template"

int m;

struct Problem {
  int cost, deadline, wa, wb;
};

void solve() {
  int n, T, a, b;
  cin >> n >> T >> a >> b;
  vector<Problem> P(n);

  int na = 0, nb = 0;
  rep(i, n) {
    int j;
    cin >> j;
    P[i].cost = j ? b : a;
    if (j) {
      P[i].wb = 1;
      ++nb;
    } else {
      ++na;
      P[i].wa = 1;
    }
  }
  rep(i, n) { cin >> P[i].deadline; }

  sort(all(P), [&](const Problem& a, const Problem& b) {
    return a.deadline < b.deadline;
  });

  vector<Problem> Q;
  {
    int i = 0;
    while (i < n) {
      Q.push_back(P[i]);
      while (i + 1 < n && P[i].deadline == P[i + 1].deadline) {
        ++i;
        Q.back().cost += P[i].cost;
        Q.back().wa += P[i].wa;
        Q.back().wb += P[i].wb;
      }
      ++i;
    }
  }

  Q.push_back(Problem{0, T + 1});

  ll ans = 0;
  ll required = 0;
  ll ca = 0, cb = 0;
  rep(i, Q.size()) {
    ll rest = Q[i].deadline - 1 - required;

    if (rest >= 0) {
      ll c = ca + cb;
      if (na - ca > 0) {
        ll dc = min(na - ca, rest / a);
        c += dc;
        rest -= a * dc;
      }
      if (nb - cb > 0) {
        ll dc = min(nb - cb, rest / b);
        c += dc;
        rest -= b * dc;
      }
      ans = max(ans, c);
    }

    required += Q[i].cost;
    ca += Q[i].wa;
    cb += Q[i].wb;
  }

  cout << ans << endl;
}

int main() {
  cin >> m;

  rep(i, m) solve();
  return 0;
}
