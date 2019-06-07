#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int digit(ll n) {
  int i = 1;
  ll j = 10;
  while(true) {
    if(n / j == 0) return i;
    i++;
    j *= 10;
  }
}

int main () {
  ll n;
  cin >> n;
  int f = 10;
  for(int i = 1, r = sqrt(n); i <= r; i++) {
    ll d = n / i;
    if(n % i == 0) {
      f = min(f, digit(d));
    }
  }
  cout << f << endl;
  return 0;
}
