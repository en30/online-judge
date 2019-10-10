#include <bits/stdc++.h>
#include "../include/template"

int N;
int main() {
  cin >> N;

  set<int> S;
  rep(i, N) {
    int A;
    cin >> A;
    S.insert(A);
  }

  int M = S.size();

  cout << ((N - M) % 2 == 0 ? M : M - 1) << endl;
  return 0;
}
