#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, H;
vector<int> a, b;

int main () {
  cin >> N >> H;
  a.resize(N), b.resize(N);
  rep(i,N)cin >> a[i] >> b[i];

  sort(all(a));
  sort(all(b));

  int ans = 0;
  int i = N - 1;
  while(H > 0 && b[i] > a[N-1] && i >= 0) {
    H -= b[i];
    ans++;
    i--;
  }

  if(H > 0) ans += (H + a[N-1] - 1) / a[N-1];

  cout << ans << endl;
  return 0;
}
