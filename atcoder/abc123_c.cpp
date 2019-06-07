#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  ll n, b;
  cin >> n;
  b = 10000000000000001LL;
  rep(i,5) {
    ll c;
    cin >> c;
    b = min(b, c);
  }

  ll g = (n+b-1)/b;
  cout << g + 4LL << endl;

  return 0;
}
