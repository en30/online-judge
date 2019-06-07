#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int x;
  cin >> x;
  x = abs(x);
  int d = 0, t = 0;
  while(x > d) {
    t++;
    d += t;
  }
  cout << t << endl;
  return 0;
}
