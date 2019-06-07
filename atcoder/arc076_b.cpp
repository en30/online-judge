#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct edge { int to, cost; };
struct node {
  int id, distance;
  node(int id, int distance) {
    this->id = id;
    this->distance = distance;
  }
  bool operator <(const node &theOther) const { return distance < theOther.distance; }
  bool operator >(const node &theOther) const { return distance > theOther.distance; }
};
int prim(vector<vector<edge>> &G) {
  int total = 0;
  int V = G.size();
  bool used[V];
  priority_queue<node, vector<node>, greater<node> > que;

  que.push(node(0, 0));
  for(int i = 0; i < V; i++) used[i] = false;

  while(!que.empty()) {
    node n = que.top(); que.pop();
    if(used[n.id]) continue;
    used[n.id] = true;
    total += n.distance;
    for(edge e : G[n.id]) {
      if(!used[e.to]) que.push(node(e.to, e.cost));
    }
  }
  return total;
}

int main () {
  int n;
  scanf("%d", &n);

  vector<pair<int, int>> x(n);
  vector<pair<int, int>> y(n);

  rep(i,n) {
    int a, b ;
    scanf("%d %d", &a, &b);
    x[i] = make_pair(a, i);
    y[i] = make_pair(b, i);
  }

  vector<vector<edge>> G(n);
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  rep(i,n-1) {
    G[x[i].second].push_back(edge {x[i+1].second, x[i+1].first - x[i].first});
    G[x[i+1].second].push_back(edge {x[i].second, x[i+1].first - x[i].first});
    G[y[i].second].push_back(edge {y[i+1].second, y[i+1].first - y[i].first});
    G[y[i+1].second].push_back(edge {y[i].second, y[i+1].first - y[i].first});
  }

  printf("%d\n", prim(G));
  return 0;
}
