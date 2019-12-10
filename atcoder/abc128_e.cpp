#include <bits/stdc++.h>
#include "../include/template"

int N, Q;
vector<int> S, T, X;
int main() {
  cin >> N >> Q;

  S.resize(N), T.resize(N), X.resize(N);

  vector<int> vals;
  rep(i, N) {
    cin >> S[i] >> T[i] >> X[i];
    vals.push_back(S[i] - X[i]);
    vals.push_back(T[i] - X[i]);
  }

  sort(all(vals));
  vals.erase(unique(all(vals)), vals.end());

  vector<vector<int>> starts(vals.size()), ends(vals.size());
  rep(i, N) {
    int j = distance(vals.begin(), lower_bound(all(vals), S[i] - X[i]));
    starts[j].push_back(i);
    j = distance(vals.begin(), lower_bound(all(vals), T[i] - X[i]));
    ends[j].push_back(i);
  }

  vector<int> mins(vals.size());
  set<pair<int, int>> s;
  rep(i, vals.size()) {
    for (int j : ends[i]) s.erase(make_pair(X[j], j));
    for (int j : starts[i]) s.insert(make_pair(X[j], j));
    mins[i] = s.empty() ? -1 : (*s.begin()).first;
  }

  rep(q, Q) {
    int D;
    cin >> D;
    int i = distance(vals.begin(), upper_bound(all(vals), D));
    if (i == 0 || i == vals.size()) {
      cout << -1 << endl;
      continue;
    }
    cout << mins[i - 1] << endl;
  }

  return 0;
}
