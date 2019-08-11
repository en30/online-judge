#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, X, Y;
vector<int> a;

int main () {
  cin >> N >> X >> Y;
  a.resize(N);

  rep(i,N) cin >> a[i];

  int ans = abs(a[N-1] - Y);
  if(N > 1) ans = max(ans, abs(a[N-1] - a[N-2]));
  cout << ans << endl;

  return 0;
}
