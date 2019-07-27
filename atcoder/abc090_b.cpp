#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B;

int main () {
  cin >> A >> B;

  int ans = 0;
  for(int i = A; i <= B; i++) {
    ans += (i%10 == i/10000) && ((i/10)%10 == (i/1000)%10);
  }
  cout << ans << endl;
  return 0;
}
