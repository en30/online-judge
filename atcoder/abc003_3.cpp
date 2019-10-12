#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> R;

int main() {
  cin >> N >> K;
  R.resize(N);
  rep(i, N) cin >> R[i];

  sort(all(R));

  double r = 0;
  rep(i, K) r = (r + R[N - K + i]) / 2.0;

  cout << setprecision(7) << r << endl;
  return 0;
}
