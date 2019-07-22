#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int L, R;
int a[2019];

int main () {
  cin >> L >> R;

  for(int i = L; i <= min(R, L+2018); i++) {
    a[i%2019] = 1;
  }

  int ans = 2018;
  for(int i = 0; i < 2019; i++) {
    if(!a[i]) continue;

    for(int j = i + 1; j < 2019; j++) {
      if(!a[j]) continue;

      ans = min(ans, (i*j) % 2019);
    }
  }

  cout << ans << endl;

  return 0;
}
