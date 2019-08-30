#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;

int main () {
  cin >> N >> K;
  int ans = 1;
  rep(i,N) {
    ans = min(ans*2, ans+K);
  }
  cout << ans << endl;
  return 0;
}
