#include <bits/stdc++.h>
#include "../include/template"

int N;
string S;

int main() {
  cin >> N >> S;

  int i = 0;
  int ans = 0;
  while (i < N) {
    if (S.substr(i, 3) == "ABC") {
      ans++;
      i += 3;
    } else {
      i++;
    }
  }

  cout << ans << endl;

  return 0;
}
