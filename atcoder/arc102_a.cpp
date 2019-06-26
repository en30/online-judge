#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, K;
  cin >> N >> K;

  ll r ;
  r = N / K;
  r = r*r*r;
  if(K % 2 == 0) {
    ll r1 = (N / (K/2) + 1) / 2;
    r += r1*r1*r1;
  }
  cout << r << endl;
  return 0;
}
