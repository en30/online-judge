#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"
#include "../include/re_rooting.hpp"

using Result = pair<int, int>;

int main() {
  int N;
  cin >> N;

  UndirectedTree T(N);
  cin >> T;

  auto reduce = [](const Result& a, const Result& b) -> Result {
    return max(a, b);
  };

  auto depth = [&](Result l, Result r) -> Result {
    Result res(reduce(l, r));
    res.first += 1;
    return res;
  };

  ReRooting<Result, Result> r(
      T.adjacencyList(), reduce, depth, [](int i) { return Result(0, i); },
      Result(-1, -1));

  int d = 0;
  vector<Result> s;
  rep(u, N) {
    if (T[u].size() < 2) continue;

    priority_queue<Result> pq;
    pq.push(Result(0, u));
    for (auto v : T[u]) pq.push(r.value(v, u));
    vector<Result> curr;
    rep(i, 3) {
      curr.push_back(pq.top());
      pq.pop();
    }
    int cd = 0;
    for (auto& p : curr) cd += p.first;
    if (chmax(d, cd)) s = curr;
  }

  cout << d << endl;
  cout << (s[0].second + 1) << " " << (s[1].second + 1) << " "
       << (s[2].second + 1) << endl;

  return 0;
}
