#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;

int main () {
  cin >> N >> K;
  int ans = 0;
  rep(i,N) {
    int x;
    cin >> x;
    ans += min(x, K-x);
  }

  cout << 2*ans << endl;
  return 0;
}
