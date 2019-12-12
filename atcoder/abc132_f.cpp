#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int N, K, M;
vector<vector<mint>> bit;

void add(int i, int a, mint w) {
  for (int x = a; x <= M; x += x & -x) bit[i][x] += w;
}

mint sum(int i, int a) {
  mint ret = 0;
  for (int x = a; x > 0; x -= x & -x) ret += bit[i][x];
  return ret;
}

int main() {
  cin >> N >> K;

  vector<int> r;

  for (int i = 1;;) {
    int j = N / (N / i) + 1;
    r.push_back(j - i);

    i = j;
    if (i > N) break;
  }

  M = r.size();
  bit = vector<vector<mint>>(K + 1, vector<mint>(M + 1, 0));

  for (int i = 0; i < M; i++) add(1, i + 1, r[i]);

  for (int i = 1; i < K; i++) {
    for (int j = 0; j < M; j++) {
      add(i + 1, j + 1, sum(i, M - j) * r[j]);
    }
  }

  cout << sum(K, M) << endl;

  return 0;
}
