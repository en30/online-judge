#include <bits/stdc++.h>
#include "../include/template"

int N, K;
string S;

int main() {
  cin >> N >> K >> S;
  S[K - 1] = (S[K - 1] - 'A') + 'a';
  cout << S << endl;
  return 0;
}
