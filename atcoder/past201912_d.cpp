#include <bits/stdc++.h>
#include "../include/template"

int N;
int main() {
  cin >> N;

  vector<int> C(N, 0);
  rep(i, N) {
    int A;
    cin >> A;
    C[A - 1] += 1;
  }

  auto it = find(all(C), 2);
  if (it == C.end()) {
    cout << "Correct" << endl;
  } else {
    int y = distance(C.begin(), find(all(C), 0)) + 1;
    int x = distance(C.begin(), it) + 1;
    cout << x << " " << y << endl;
  }

  return 0;
}
