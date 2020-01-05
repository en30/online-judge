#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;

  int c = 0;
  double sum = 0;
  rep(i, N) {
    int A;
    cin >> A;
    if (A == 0) continue;
    sum += A;
    ++c;
  }

  cout << ceil(sum / c) << endl;
  return 0;
}
