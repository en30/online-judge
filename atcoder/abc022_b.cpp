#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  unordered_set<int> s;
  int ans = 0;
  rep(i, N) {
    int A;
    cin >> A;
    if (s.find(A) != s.end()) ++ans;
    s.insert(A);
  }

  cout << ans << endl;

  return 0;
}
