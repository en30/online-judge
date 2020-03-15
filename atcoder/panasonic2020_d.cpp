#include <bits/stdc++.h>
#include "../include/template"

int N;

void rec(int i, int k, string s) {
  if (i == N) {
    cout << s << endl;
    return;
  }

  rep(j, k) rec(i + 1, max(k, j + 2), s + char(j + 'a'));
}

int main() {
  cin >> N;

  rec(1, 2, "a");
  return 0;
}
