#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, D, X;

int main () {
  cin >> N >> D >> X;

  int ans = X;
  rep(i,N) {
    int A;
    cin >> A;
    for(int j = 1; j <= D; j += A) ans++;
  }

  cout << ans << endl;
  return 0;
}
