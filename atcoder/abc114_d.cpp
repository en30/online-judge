#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> c(n+1, 0);

  for(int i = 2; i <= n; i++) {
    int k = i;
    for(int j = 2; j <= i; j++) {
      while(k % j == 0) {
        c[j]++;
        k /= j;
      }
    }
  }


  vector<int> dp(76, 0);
  dp[1] = 1;

  for(int i = 0; i < c.size(); i++) {
    if(c[i]) for(int j = 75; j >= 0; j--) {
      for(int x = 1; x <= c[i]; x++) {
        if(j*(x+1) <= 75) dp[j*(x+1)] += dp[j];
      }
    }
  }

  cout << dp[75] << endl;

  return 0;
}
