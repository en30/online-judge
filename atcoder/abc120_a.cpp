#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int A, B, C;
  cin >> A >> B >> C;

  int ans = A*C >= B ? B/A : C;
  cout << ans << endl;

  return 0;
}
