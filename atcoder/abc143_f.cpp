#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> A, c, S;

int main() {
  map<int, int> m;
  cin >> N;
  A.resize(N);
  rep(i, N) {
    cin >> A[i];
    m[A[i]]++;
  }

  for (auto it = m.begin(); it != m.end(); it++) c.push_back((*it).second);
  sort(all(c));
  S.resize(c.size() + 1, 0);
  rep(i, c.size()) S[i + 1] = S[i] + c[i];

  int l = 0;
  for (int k = 1; k <= N; ++k) {
    int n = c.size() - 1 - l;
    while (c[n] * (k - l) > S[n + 1]) {
      --n;
      ++l;
    }
    cout << S[n + 1] / (k - l) << endl;
  }

  return 0;
}
