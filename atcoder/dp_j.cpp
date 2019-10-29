#include <bits/stdc++.h>
#include "../include/template"

const int MAX_N = 301;
int N;
vector<int> a;

double dp[MAX_N][MAX_N][MAX_N];
double solve(int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  if (i == 0 && j == 0 && k == 0) return 0.0;

  double res = N;
  if (i > 0) res += i * solve(i - 1, j, k);
  if (j > 0) res += j * solve(i + 1, j - 1, k);
  if (k > 0) res += k * solve(i, j + 1, k - 1);
  res /= (i + j + k);

  return dp[i][j][k] = res;
}

int main() {
  cin >> N;
  a.resize(N);

  map<int, int> c;
  rep(i, N) {
    cin >> a[i];
    c[a[i]]++;
  }
  rep(i, N + 1) rep(j, N + 1) rep(k, N + 1) dp[i][j][k] = -1;

  cout << setprecision(10) << solve(c[1], c[2], c[3]) << endl;

  return 0;
}
