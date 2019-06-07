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

typedef pair<int, int> edge;
const int UNVISITED = -1;
priority_queue<edge, vector<edge>, greater<edge>> bridges;
vector<int> low;
vector<int> dist;
vector<vector<int>> adjacentList;

int dfs(int i, int d, int parent) {
  low[i] = d;
  dist[i] = d;
  for(auto n: adjacentList[i]) {
    if(dist[n] == UNVISITED) {
      low[i] = min(low[i], dfs(n, d+1, i));
      if(d < low[n]) {
        bridges.push(edge(min(i,n), max(i,n)));
      }
    } else if(parent != n) {
      low[i] = min(low[i], dist[n]);
    }
  }
  return low[i];
}

int main () {
  int V, E;
  cin >> V >> E;
  low = vector<int>(V, 0);
  dist = vector<int>(V, UNVISITED);
  adjacentList = vector<vector<int>>(V);

  for(int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    adjacentList[s].push_back(t);
    adjacentList[t].push_back(s);
  }

  dfs(0, 0, -1);

  while(!bridges.empty()) {
    edge e = bridges.top(); bridges.pop();
    printf("%d %d\n", e.first, e.second);
  }

  return 0;
}
