#include <bits/stdc++.h>
#include "../include/template"

int N;
map<int, int> m;
int main() {
  cin >> N;
  rep(i, N) {
    int A;
    cin >> A;
    m[A]++;
  }

  ll ans = 0;
  for (auto it = m.rbegin(); it != m.rend(); ++it) {
    if ((*it).second >= 4 && ans == 0) {
      ans = ll((*it).first) * ((*it).first);
      break;
    }
    if ((*it).second >= 2) {
      if (ans != 0) {
        ans *= (*it).first;
        break;
      }
      ans = (*it).first;
    }
  }

  cout << ans << endl;

  return 0;
}
