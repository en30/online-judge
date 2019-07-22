#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int MAX_V = 1e5;
const int MAX_LOG_V = 20;

int N, Q;

struct edge {
  int dest, color, distance;
};

vector<edge> G[MAX_V];
const int root = 0;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
set<int> relevantColor[MAX_V];

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for(auto &e: G[v]) {
    if (e.dest != p) dfs(e.dest, v, d+1);
  }
}

void initLCA(int V) {
  dfs(root, -1, 0);
  for(int k = 0; k + 1 < MAX_LOG_V; k++) {
    for(int v = 0; v < V; v++) {
      if(parent[k][v] < 0) {
        parent[k+1][v] = -1;
      } else {
        parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }
}

int lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; k++) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

struct query {
  int x, y, u, v, lca;
};

map<int, map<int, int>> colorDistance;
map<int, map<int, int>> colorNum;
int monochroDistance[MAX_V];
int tmpColorDist[MAX_V-1];
int tmpColorNum[MAX_V-1];

void collectDistances(int u, int p) {
  for(int c: relevantColor[u]) {
    colorDistance[c][u] = tmpColorDist[c];
    colorNum[c][u] = tmpColorNum[c];
  }

  for(auto &e: G[u]) {
    if(e.dest != p) {
      tmpColorDist[e.color] += e.distance;
      tmpColorNum[e.color]++;
      monochroDistance[e.dest] = monochroDistance[u] + e.distance;
      collectDistances(e.dest, u);
      tmpColorDist[e.color] -= e.distance;
      tmpColorNum[e.color]--;
    }
  }
}

int distanceBetweenNodes(auto &d, query &q) {
  return d[q.u] + d[q.v] - 2 * d[q.lca];
};

int main () {
  cin >> N >> Q;

  rep(i,N-1) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--;b--;c--;
    G[a].push_back(edge{b, c, d});
    G[b].push_back(edge{a, c, d});
  }

  initLCA(N);

  vector<query> queries(Q);
  rep(i,Q) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    x--;u--;v--;
    int l = lca(u,v);
    queries[i] = query{x, y, u, v, l};
    relevantColor[u].insert(x);
    relevantColor[v].insert(x);
    relevantColor[l].insert(x);
  }

  collectDistances(root, -1);

  for(auto &q: queries) {
    int d = distanceBetweenNodes(monochroDistance, q);
    int cd = distanceBetweenNodes(colorDistance[q.x], q);
    int n = distanceBetweenNodes(colorNum[q.x], q);
    cout << d - cd + n*q.y << endl;
  }

  return 0;
}
