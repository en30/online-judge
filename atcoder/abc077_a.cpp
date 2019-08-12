#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

char c[2][3];

bool ok() {
  return c[0][0] == c[1][2] && c[0][1] == c[1][1] && c[0][2] == c[1][0];
}

int main () {
  rep(i,2)rep(j,3) cin >> c[i][j];

  cout << (ok() ? "YES" : "NO") << endl;

  return 0;
}
