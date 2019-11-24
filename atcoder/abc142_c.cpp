#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;

  vector<int> ans(N);
  rep(i, N) {
    int A;
    cin >> A;
    ans[A - 1] = i + 1;
  }

  rep(i, N) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
