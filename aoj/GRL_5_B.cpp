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

struct edge { int dest, weight, height; };

int dfs(int prev, int node, vector<vector<edge>> &adjacentList) {
  int res = 0;
  for(edge &e : adjacentList[node]) {
    if(e.dest == prev) continue;
    if(e.height == -1) e.height = e.weight + dfs(node, e.dest, adjacentList);
    res = max(res, e.height);
  }
  return res;
}

vector<int> heightsOfTree(vector<vector<edge>> &adjacentList) {
  int n = adjacentList.size();
  vector<int> heights(n);
  for(int i = 0; i < n; i++)heights[i] = dfs(-1, i, adjacentList);
  return heights;
}

int main () {
  int n;
  cin >> n;
  vector<vector<edge>> adjacentList(n, vector<edge>());
  for(int i = 0; i < n - 1; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    adjacentList[s].push_back(edge {t, w, -1});
    adjacentList[t].push_back(edge {s, w, -1});
  }

  vector<int> heights = heightsOfTree(adjacentList);
  for(int i: heights) {
    cout << i << endl;
  }

  return 0;
}
