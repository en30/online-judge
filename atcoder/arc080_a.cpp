#include <bits/stdc++.h>
#include "../include/template"

int N;
int c[3];

int main() {
  cin >> N;
  rep(i, N) {
    int a;
    cin >> a;
    if (a % 4 == 0) {
      c[2]++;
    } else if (a % 2 == 0) {
      c[1]++;
    } else {
      c[0]++;
    }
  }

  cout << ((c[2] >= c[0] + (c[1] >= 1) - 1) ? "Yes" : "No") << endl;
  return 0;
}
