#include <bits/stdc++.h>
#include "../include/template"

int N, M;
const int INF = 1e9;
int S = 1e9;
vector<vector<int>> G;
stack<int> ans;

void search(int s) {
  vector<int> d(N, INF), prev(N, -1);
  queue<int> q;
  q.push(s);

  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : G[u]) {
      if (v == s) {
        if (S > d[u]) {
          S = d[u];
          ans = stack<int>();
          while (u != -1) {
            ans.push(u);
            u = prev[u];
          }
          return;
        }
      }
      if (d[v] > d[u] + 1) {
        prev[v] = u;
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N >> M;
  G.resize(N);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
  }

  rep(i, N) search(i);

  if (ans.size() == 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << ans.size() << endl;
  while (!ans.empty()) {
    cout << (ans.top() + 1) << endl;
    ans.pop();
  }

  return 0;
}
