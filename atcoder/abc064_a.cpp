#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int r,g,b;
  cin >> r >> g >> b;
  cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}
