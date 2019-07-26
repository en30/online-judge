#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int n;
vector<int> a;

int main () {
  cin >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];

  sort(all(a));

  int m = a[n-1];
  int i = distance(a.begin(), lower_bound(all(a), m/2));
  if(i == n - 1 || abs(a[i] - m/2) > abs(a[i-1] - m/2)) i--;

  cout << m << " " << a[i] << endl;

  return 0;
}
