#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C;
int main () {
  cin >> A >> B >> C;

  vector<int> a = {A, B, C};
  sort(all(a));

  int ans = a[2] - a[1];
  a[0] += ans;
  ans += (a[2] - a[0] + 1) / 2 + ((a[2] - a[0]) & 1);
  cout << ans << endl;
  return 0;
}
