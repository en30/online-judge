#include <bits/stdc++.h>
#include "../include/template"

ll N, A, B;

int main() {
  cin >> N >> A >> B;
  if (A > B) swap(A, B);
  if ((A + B) % 2) {
    cout << min(B - (-A + 1), (N + (N - B + 1)) - A) / 2 << endl;
  } else {
    cout << (B - A) / 2 << endl;
  }

  return 0;
}
