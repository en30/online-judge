#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int X;
  cin >> X;
  int ans = 1;
  for(int i = 2; i <= sqrt(1000); i++) {
    for(int j = i*i; j <= X; j *= i) {
      ans = max(ans, j);
    }
  }
  cout << ans << endl;

  return 0;
}
