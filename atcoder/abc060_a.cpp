#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string a,b,c;
  cin >> a >> b >> c;
  cout << (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0] ? "YES" : "NO") << endl;
  return 0;
}
