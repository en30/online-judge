#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll N;
  cin >> N;

  if (N == 1) {
    cout << "Aoki" << endl;
    return 0;
  }

  bool win = (N % 2);
  int i = 1;
  while (N != 1) {
    win = !(win & ((i + N) % 2));
    N /= 2;
    ++i;
  }
  cout << (win ? "Takahashi" : "Aoki") << endl;
  return 0;
}
