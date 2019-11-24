#include <bits/stdc++.h>
#include "../include/template"

int N;
string S;

int main() {
  cin >> N >> S;

  if (N % 2) {
    cout << "No" << endl;
    return 0;
  }

  rep(i, N / 2) {
    if (S[i] != S[i + N / 2]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
