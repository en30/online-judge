#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  vector<int> T(N);
  rep(i, N) cin >> T[i];
  cout << *min_element(all(T)) << endl;

  return 0;
}
