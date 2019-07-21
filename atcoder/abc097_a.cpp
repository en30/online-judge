#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << ((abs(c-a) <= d || (abs(a-b) <= d && abs(b-c) <= d)) ? "Yes" : "No") << endl;
  return 0;
}
