#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

class DAG {
public:
  vector<int> topologicalSorted;
  bool valid;

  DAG(vector<vector<int>> G) {
    int V = G.size();
    vector<int> inDegree(G.size(), 0);
    for(int u = 0; u < V; u++) {
      for(auto v: G[u]) inDegree[v]++;
    }
    stack<int> s;
    for(int u = 0; u < V; u++) if(inDegree[u] == 0) s.push(u);

    while(!s.empty()) {
      int u = s.top();
      s.pop();
      topologicalSorted.push_back(u);
      for(auto &v: G[u]) {
        inDegree[v]--;
        if(inDegree[v] == 0) s.push(v);
      }
    }

    valid = static_cast<int>(topologicalSorted.size()) == V;
  }
};

vector<int> offset;
vector<vector<int>> G;

int index(int x, int y) {
  int l = min(x,y), r = max(x,y);
  return offset[l] + (r - l - 1);
}

vector<int> d;
int dfs(int i) {
  if(d[i] != -1) return d[i];

  d[i] = 1;
  for(int j: G[i]) {
    d[i] = max(d[i], 1 + dfs(j));
  }
  return d[i];
}

int main () {
  cin >> N;

  offset.resize(N, 0);
  for(int i = 1; i < N; i++) {
    offset[i] = offset[i-1] + N - i;
  }

  int M = N*(N-1)/2;
  G.resize(M);

  rep(i,N) {
    int a;
    cin >> a;
    int idx = index(i, a-1);
    rep(j,N-2) {
      cin >> a;
      int nidx = index(i,a-1);
      G[idx].push_back(nidx);
      idx = nidx;
    }
  }

  DAG dag(G);
  if(!dag.valid) {
    cout << "-1" << endl;
    return 0;
  }

  d.resize(M, -1);
  int ans = M;
  for(int i: dag.topologicalSorted) dfs(i);

  cout << *max_element(all(d)) << endl;

  return 0;
}
