#include <bits/stdc++.h>
#include "../include/template"

int N, M, D;
vector<int> A;

struct Group {
  vector<int> elems;
};

int main() {
  cin >> N >> M >> D;
  A.resize(M);
  rep(i, M) {
    cin >> A[i];
    --A[i];
  }

  vector<int> B(N);
  rep(i, N) B[i] = i;

  for (int i = M - 1; i >= 0; --i) {
    swap(B[A[i]], B[A[i] + 1]);
  }

  vector<bool> used(N, false);
  vector<Group> group;
  vector<int> g(N);
  vector<int> index(N);
  set<int> s;
  rep(i, N) {
    if (used[i]) continue;

    int id = group.size();
    Group e;

    int j = i;
    do {
      used[j] = true;
      g[j] = id;
      index[j] = e.elems.size();
      e.elems.push_back(j);
      j = B[j];
    } while (j != i);

    group.push_back(e);
  }

  rep(i, N) {
    Group& e = group[g[i]];
    cout << e.elems[(index[i] + D) % int(e.elems.size())] + 1 << endl;
  }

  return 0;
}
