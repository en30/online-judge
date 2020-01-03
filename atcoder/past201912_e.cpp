#include <bits/stdc++.h>
#include "../include/template"

int N, Q;
int main() {
  cin >> N >> Q;

  vector<set<int>> followers(N), friends(N);

  auto follow = [&](int x, int y) {
    followers[y].insert(x);
    friends[x].insert(y);
  };

  rep(i, Q) {
    int t, a, b;
    cin >> t >> a;
    --a;
    if (t == 1) {
      cin >> b;
      --b;
      follow(a, b);
    } else if (t == 2) {
      for (int b : followers[a]) follow(a, b);
    } else {
      for (int x : set<int>(friends[a])) {
        for (int b : friends[x]) {
          if (a != b) follow(a, b);
        }
      }
    }
  }

  rep(i, N) {
    rep(j, N) {
      if (friends[i].find(j) != friends[i].end()) {
        cout << 'Y';
      } else {
        cout << 'N';
      }
    }
    cout << endl;
  }

  return 0;
}
