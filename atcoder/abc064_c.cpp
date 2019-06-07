#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, l = 0, u = 0;
  vector<int> used(8, 0);

  cin >> n;
  rep(i,n) {
    int a;
    cin >> a;
    int r = a / 400;
    if(r < 8 && !used[r]) {
      used[r] = 1;
      l++;
      u++;
    }
    if(r >= 8) u++;
  }

  if(l == 0) l = 1;

  printf("%d %d\n", l, u);
  return 0;
}
