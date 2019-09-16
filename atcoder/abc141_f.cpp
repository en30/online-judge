#include <bits/stdc++.h>
#include "../include/template"

typedef bitset<64> bs;

int N;
vector<bs> A;

int main() {
  cin >> N;
  A.resize(N);
  rep(i, N) {
    ll a;
    cin >> a;
    A[i] = bs(a);
  }

  const int D = 60;
  bs allXor;
  rep(i, N) allXor ^= A[i];
  rep(i, N) A[i] &= ~allXor;

  int idx = 0;
  for (int d = D - 1; d >= 0; --d) {
    int j = idx;
    while (j < N && !A[j][d]) ++j;
    if (j < N) {
      swap(A[idx], A[j]);
      rep(k, N) {
        if (k != idx && A[k][d]) {
          A[k] ^= A[idx];
        }
      }
      ++idx;
    }
  }

  unsigned long long ans = 0;
  rep(i, N) ans = max(ans, ans ^ A[i].to_ullong());
  ans <<= 1;
  ans += allXor.to_ullong();

  cout << ans << endl;

  return 0;
}
