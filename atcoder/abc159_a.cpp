#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, M;
  cin >> N >> M;
  cout << N * (N - 1) / 2 + M * (M - 1) / 2 << endl;
  return 0;
}
