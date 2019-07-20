#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int INF = 1e9;

int f(int n, int r) {
  int res = 0;

  while(n != 0) {
    res += n % r;
    n /= r;
  }

  return res;
}

int main () {
  int N;
  cin >> N;

  int ans = INF;
  for(int i = 0; i <= N; i++) {
    ans = min(ans, f(i, 6) + f(N-i, 9));
  }

  cout << ans << endl;

  return 0;
}
