#include <bits/stdc++.h>
#include "../include/template"

ll N;

int main() {
  cin >> N;

  for (int i = sqrt(N); i > 0; --i) {
    if (N % i == 0) {
      cout << (i + N / i - 2) << endl;
      return 0;
    }
  }
  return 0;
}
