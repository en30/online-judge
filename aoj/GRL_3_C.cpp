#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

vector<int> stronglyConnectedComponent(vector<vector<int>> adjacentList) {
  const int UNVISITED = -1;
  int V = adjacentList.size();
  vector<int> low(V, 0);
  vector<int> dist(V, UNVISITED);
  vector<int> component(V, -1);
  stack<int> path;
  int t = 0;
  int cid = 0;

  function<int (int)> dfs = [&](int i) -> int {
    t++;
    low[i] = t;
    dist[i] = t;
    path.push(i);

    for(auto n: adjacentList[i]) {
      if(dist[n] == UNVISITED) {
        low[i] = min(low[i], dfs(n));
      } else if(component[n] == -1) {
        low[i] = min(low[i], dist[n]);
      }
    }

    if(dist[i] == low[i]) {
      cid++;
      while(!path.empty()) {
        int v = path.top(); path.pop();
        component[v] = cid;
        if(v == i)break;
      }
    }
    return low[i];
  };

  for(int i = 0; i < V; i++)if(dist[i] == UNVISITED)dfs(i);
  return component;
}


int main () {
  int V, E, Q;
  cin >> V >> E;
  vector<vector<int>> adjacentList(V);

  for(int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    adjacentList[s].push_back(t);
  }

  vector<int> component = stronglyConnectedComponent(adjacentList);

  cin >> Q;

  for(int i = 0; i < Q; i++){
    int u, v;
    cin >> u >> v;
    cout << (component[v] == component[u]) << endl;
  }
  return 0;
}
