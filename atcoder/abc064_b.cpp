#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)


int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());

  cout << abs(a[0] - a[n-1]) << endl;

  return 0;
}
