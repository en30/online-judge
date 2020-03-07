#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;

  string rpre = "", suf = "";
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
      if ((F == 1 && reversed) || (F == 2 && !reversed)) {
        suf += C;
      } else {
        rpre += C;
      }
    }
  }

  if (reversed) {
    reverse(all(s));
    reverse(all(suf));
    cout << suf << s << rpre << endl;
  } else {
    reverse(all(rpre));
    cout << rpre << s << suf << endl;
  }

  return 0;
}
