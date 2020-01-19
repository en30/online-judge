#include <bits/stdc++.h>
#include "../include/template"

int N;

int f(int n) {
  if (n / 10 == 0) return n;
  return f(n / 10);
}

int main() {
  cin >> N;
  unordered_map<int, unordered_map<int, int>> c;

  for (int i = 1; i <= N; ++i) {
    int tail = (i % 10);
    int head = f(i);
    c[head][tail] += 1;
  }

  int ans = 0;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      ans += c[i][j] * c[j][i];
    }
  }
  cout << ans << endl;

  return 0;
}
