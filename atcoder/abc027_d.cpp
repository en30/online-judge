#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  const int N = S.size();

  vector<int> diff;
  for (int i = N - 1, np = 0, nn = 0; i >= 0; --i) {
    if (S[i] == 'M') {
      diff.push_back(np - nn);
    } else if (S[i] == '+') {
      ++np;
    } else {
      ++nn;
    }
  }
  sort(all(diff));
  const int M = diff.size();

  auto head = diff.begin();
  cout << accumulate(head + M / 2, head + M, 0) -
              accumulate(head, head + M / 2, 0)
       << endl;

  return 0;
}
