#include <bits/stdc++.h>
#include "../include/template"

int N;

void dfs(int i, string s) {
  if (N == i) {
    cout << s << endl;
    return;
  }
  dfs(i + 1, s + "a");
  dfs(i + 1, s + "b");
  dfs(i + 1, s + "c");
}

int main() {
  cin >> N;

  dfs(0, "");
  return 0;
}
