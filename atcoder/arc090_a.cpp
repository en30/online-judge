#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

vector<vector<int>> A;

int solve(int i, int j) {
  if(i == 1 && j == N-1) return A[i][j];

  int res = 0;
  if(j != N - 1) res = max(res, A[i][j] + solve(i, j+1));
  if(i != 1) res = max(res, A[i][j] + solve(i + 1, j));
  return res;
}

int main () {
  cin >> N;

  A.resize(2, vector<int>(N));

  rep(i,2) rep(j,N) cin >> A[i][j];
  cout << solve(0, 0) << endl;
  return 0;
}
