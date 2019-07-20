#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int INF = 1e9;
int main () {
  int N;
  cin >> N;

  vector<int> v;
  v.push_back(1);
  for(int x = 6; x <= N; x *= 6) {
    v.push_back(x);
  }
  for(int x = 9; x <= N; x *= 9) {
    v.push_back(x);
  }

  int M = v.size();
  vector<vector<int>> dp(M+1, vector<int>(N+1, INF));
  dp[0][0] = 0;
  for(int i = 0; i < M; i++) {
    for(int j = 0; j <= N; j++) {
      dp[i+1][j] = dp[i][j];
      if(j-v[i] >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-v[i]] + 1);
    }
  }

  cout << dp[M][N] << endl;

  return 0;
}
