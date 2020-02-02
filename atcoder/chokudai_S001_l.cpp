#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  vector<int> ideal(N);
  rep(i, N) {
    int a;
    cin >> a;
    --a;
    ideal[i] = a;
  }

  vector<bool> used(N, false);

  int ans = 0;
  rep(i, N) {
    if (used[i]) continue;

    int c = 0;
    for (int j = ideal[i]; j != i; j = ideal[j]) {
      used[j] = true;
      ++c;
    }
    ans += c;
  }

  cout << (ans <= N && (N - ans) % 2 == 0 ? "YES" : "NO") << endl;

  return 0;
}
