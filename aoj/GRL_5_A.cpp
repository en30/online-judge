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

struct edge { int dest, weight; };
struct result { int dest, distance; };

result dfs(int previous, int node, vector<vector<edge>> &adjacentList) {
  result r = {node, 0};
  for(edge e: adjacentList[node]) if(e.dest != previous){
      result t = dfs(node, e.dest, adjacentList);
      t.distance += e.weight;
      if(r.distance < t.distance) r = t;
  }
  return r;
}

int diameterOfTree(vector<vector<edge>> &adjacentList) {
  result r = dfs(-1, 0, adjacentList);
  result t = dfs(-1, r.dest, adjacentList);
  return t.distance;
}

int main () {
  int N;
  cin >> N;

  vector<vector<edge>> adjacentList(N);

  REP(i,N-1) {
    int s,t,w;
    cin >> s >> t >> w;
    adjacentList[s].push_back(edge {t,w});
    adjacentList[t].push_back(edge {s,w});
  }

  cout << diameterOfTree(adjacentList) << endl;
  return 0;
}
