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

stack<int> topologicalSort(vector<vector<int>>adjacentList)  {
  int V = adjacentList.size();
  stack<int> sorted;
  vector<bool> visited(V, false);

  function<void (int)> dfs = [&](int i) {
    if(visited[i]) return;
    visited[i] = true;
    for(int nn: adjacentList[i]) dfs(nn);
    sorted.push(i);
  };

  for(int i = 0; i < V; i++) dfs(i);

  return sorted;
}

int main () {
  int V, E;
  cin >> V >> E;

  vector<vector<int>> adjacentList(V, vector<int>());

  REP(i,E) {
    int s, t;
    cin >> s >> t;
    adjacentList[s].push_back(t);
  }

  stack<int> sorted = topologicalSort(adjacentList);

  while(!sorted.empty()) {
    cout << sorted.top() << endl;
    sorted.pop();
  }

  return 0;
}
