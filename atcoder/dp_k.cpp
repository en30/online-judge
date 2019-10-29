#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> a, grundy;
int main() {
  cin >> N >> K;
  a.resize(N), grundy.resize(K + 1, 0);
  rep(i, N) cin >> a[i];

  rep(k, K + 1) {
    set<int> s;
    for (int i = 0; i < N && k - a[i] >= 0; ++i) {
      s.insert(grundy[k - a[i]]);
    }
    int g = 0;
    while (s.find(g) != s.end()) ++g;
    grundy[k] = g;
  }

  cout << (grundy[K] ? "First" : "Second") << endl;

  return 0;
}
