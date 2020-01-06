#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<vector<int>> G;
int main() {
  cin >> N >> M;
  G.resize(N);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  rep(i, N) {
    set<int> s;
    for (int j : G[i]) {
      for (int k : G[j]) {
        s.insert(k);
      }
    }
    s.erase(i);
    for (int j : G[i]) s.erase(j);
    cout << s.size() << endl;
  }
  return 0;
}
