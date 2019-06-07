#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main () {
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}
