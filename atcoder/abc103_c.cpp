#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;
  int ans = 0;
  rep(i,N) {
    int a;
    cin >> a;
    ans += a - 1;
  }
  cout << ans << endl;
  return 0;
}
