#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;

int main () {
  cin >> N;

  int ans = 0;
  rep(i,N) {
    int a;
    cin >> a;
    while(a % 2 == 0) {
      a /= 2;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
