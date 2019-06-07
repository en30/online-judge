#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a,b;
  cin >> a >> b;

  cout << max(a + (a-1), max(b + (b-1), a + b)) << endl;

  return 0;
}
