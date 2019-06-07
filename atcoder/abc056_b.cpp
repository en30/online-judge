#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int w, a, b;
  cin >> w >> a >> b;
  if(b > a + w) {
    cout << (b - a - w);
  } else if(b + w < a) {
    cout << (a - b - w);
  } else {
    cout << 0;
  }
  cout << endl;
  return 0;
}
