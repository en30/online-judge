#include <bits/stdc++.h>
#include "../include/template"

int N, M;

int main() {
  cin >> N >> M;

  priority_queue<int> pq;
  rep(i, N) {
    int A;
    cin >> A;
    pq.push(A);
  }
  rep(i, M) {
    int A = pq.top();
    pq.pop();
    pq.push(A / 2);
  }
  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
  return 0;
}
