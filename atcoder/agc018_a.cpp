#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main () {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  bool in = false;
  rep(i,n) {
    cin >> a[i];
    if(a[i] == k) in = true;
  }
  sort(a.begin(), a.end());

  int res = a[0];
  for(int i = 1; i < n; i++) {
    res = gcd(res, a[i]);
  }

  if(in || (a[n-1] > k && k % res == 0)) {
    printf("POSSIBLE\n");
  } else  {
    printf("IMPOSSIBLE\n");
  }
  return 0;
}
