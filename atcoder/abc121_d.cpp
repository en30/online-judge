#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

ll f(ll A, ll B, int b) {
  if(A != 0) return f(0, A-1, b) ^ f(0, B, b);
  if(B == 3) return 0;
  if(B == 2) return 3;
  if(B == 1) return 1;
  if(B == 0) return 0;

  while(!(B >> b & 1)) b--;
  ll x = 1LL << b;
  return f(0, B ^ x, b-1) + (~B & 1) * x;
}

int main () {
  ll A, B;

  cin >> A >> B;

  cout << f(A, B, 40) << endl;

  return 0;
}
