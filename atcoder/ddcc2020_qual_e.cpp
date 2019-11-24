#include <bits/stdc++.h>
#include "../include/template"

int N;
int main() {
  cin >> N;
  vector<int> isRed(2 * N, -1);

  string lRes;
  cout << "?";
  rep(i, N) cout << " " << (i + 1);
  cout << endl;
  cin >> lRes;

  // [l, r)
  int l = 0, r = N;
  while (r - l > 1) {
    int m = (l + r) / 2;

    cout << "?";
    rep(i, N) cout << " " << (m + i + 1);
    cout << endl;

    string res;
    cin >> res;
    if (res == lRes) {
      l = m;
    } else {
      r = m;
    }
  }

  isRed[l] = (lRes == "Red");
  isRed[l + N] = !isRed[l];

  string sIn = "?", sOut = "?";
  rep(i, 2 * N) {
    if (i == l || i == l + N) continue;
    if (l < i && i < l + N) {
      sIn += " " + to_string(i + 1);
    } else {
      sOut += " " + to_string(i + 1);
    }
  }

  rep(i, 2 * N) {
    if (i == l || i == l + N) continue;
    if (l < i && i < l + N) {
      cout << sOut;
    } else {
      cout << sIn;
    }
    cout << " " << (i + 1) << endl;

    string res;
    cin >> res;
    isRed[i] = (res == "Red");
  }

  cout << "! ";
  rep(i, 2 * N) cout << (isRed[i] ? "R" : "B");
  cout << endl;
  return 0;
}
