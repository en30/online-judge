#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (A < B) swap(A, B);
  int ans = C / B;
  ans += (C % B) / A;
  cout << ans << endl;
  return 0;
}
