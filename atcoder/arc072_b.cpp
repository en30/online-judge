#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  if(b - a == c - b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
