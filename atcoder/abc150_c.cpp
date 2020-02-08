#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  vector<int> P(N), Q(N);
  rep(i, N) cin >> P[i];
  rep(i, N) cin >> Q[i];

  vector<int> a(N);
  rep(i, N) a[i] = i + 1;

  int p, q;
  int i = 0;
  do {
    bool same = true;
    rep(i, N) same &= P[i] == a[i];
    if (same) p = i;

    same = true;
    rep(i, N) same &= Q[i] == a[i];
    if (same) q = i;

    ++i;
  } while (next_permutation(all(a)));

  cout << abs(p - q) << endl;

  return 0;
}
