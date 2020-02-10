#include <bits/stdc++.h>
#include "../include/template"
#include "../include/knapsack.hpp"

int main() {
  int N, W;
  cin >> N >> W;
  vector<ll> v(N), w(N);
  rep(i, N) cin >> v[i] >> w[i];

  Knapsack knapsack(v, w, W);
  if (N <= 30) {
    cout << knapsack.splitAndList() << endl;
  } else if ((*max_element(all(w))) <= 1000) {
    cout << knapsack.valueMaximizationDP() << endl;
  } else {
    cout << knapsack.weightMinimizationDP() << endl;
  }

  return 0;
}
