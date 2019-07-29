#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int A, B, C ,X;
  cin >> A >> B >> C >> X;

  int ans = 0;
  rep(i,A+1) rep(j,B+1) rep(k,C+1) {
    if(500*i + 100*j + 50*k == X) ans++;
  }

  cout << ans << endl;
  return 0;
}
