#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, K;
vector<int> A;

int main () {
  cin >> N >> K;
  A.resize(N);
  rep(i,N) cin >> A[i];

  int ans = 1e9;
  for(int i = 0; i < K-1; i++){
    ans = min(ans, (N + i - 1 + K - 2)/(K-1));
  }

  cout << ans << endl;

  return 0;
}
