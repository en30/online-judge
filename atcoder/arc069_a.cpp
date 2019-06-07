#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  ll n, m;
  cin >> n >> m;

  if(n > m / 2) {
    cout << m/2 << endl;
  } else {
    cout << (n + (m - 2 * n) / 4) << endl;
  }

  return 0;
}
