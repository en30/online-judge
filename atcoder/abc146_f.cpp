#include <bits/stdc++.h>
#include "../include/template"

int N, M;
string S;

int main() {
  cin >> N >> M >> S;

  stack<int> m;
  int i = N;
  while (i != 0) {
    bool found = false;
    for (int j = i - M; j < i; ++j) {
      if (j >= 0 && S[j] == '0') {
        m.push(i - j);
        i = j;
        found = true;
        break;
      }
    }
    if (!found) break;
  }

  if (i != 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << m.top();
  m.pop();
  while (!m.empty()) {
    cout << " " << m.top();
    m.pop();
  }
  cout << endl;

  return 0;
}
