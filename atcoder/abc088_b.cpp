#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> a;

int main () {
  cin >> N;
  a.resize(N);
  rep(i,N)cin >> a[i];
  sort(all(a));

  int ans = 0;
  rep(i,N) {
    if(i&1) {
      ans -= a[N-1-i];
    } else {
      ans += a[N-1-i];
    }
  }

  cout << ans << endl;
  return 0;
}
