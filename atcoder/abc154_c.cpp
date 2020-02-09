#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  unordered_map<int, int> m;
  rep(i, N) {
    int A;
    cin >> A;
    m[A] = 1;
  }
  cout << (m.size() == N ? "YES" : "NO") << endl;
  return 0;
}
