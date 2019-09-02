#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B;

int main () {
  cin >> A >> B;

  int c = 1;
  int ans = 0;
  while(B > c) {
    c += A - 1;
    ans++;
  }

  cout << ans << endl;
  return 0;
}
