#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string S, T;

int main () {
  cin >> S >> T;
  int ans = 0;
  rep(i,3) {
    if(S[i] == T[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}
