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
