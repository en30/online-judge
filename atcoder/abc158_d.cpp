#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  deque<char> s;
  for (char c : S) s.push_back(c);

  int Q;
  cin >> Q;
  bool reversed = false;
  rep(i, Q) {
    int T;
    cin >> T;
    if (T == 1) {
      reversed = !reversed;
    } else {
      int F;
      char C;
      cin >> F >> C;
      if ((F == 1) ^ reversed) {
        s.push_front(C);
      } else {
        s.push_back(C);
      }
    }
  }

  if (reversed) reverse(all(s));
  for (char c : s) cout << c;
  cout << endl;

  return 0;
}
