#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> c(n+1, 0);

  for(int i = 2; i <= n; i++) {
    int k = i;
    for(int j = 2; j <= i; j++) {
      while(k % j == 0) {
        c[j]++;
        k /= j;
      }
    }
  }

  int ans = 0;
  int k_2 = 0, k_4 = 0, k_14 = 0, k_24 = 0, k_74 = 0;
  for(int i : c) {
    if(i >= 2) k_2++;
    if(i >= 4) k_4++;
    if(i >= 14) k_14++;
    if(i >= 24) k_24++;
    if(i >= 74) k_74++;
  }
  ans += k_4*(k_4-1)*(k_2-2)/2;
  ans += k_24*(k_2-1);
  ans += k_14*(k_4-1);
  ans += k_74;

  cout << ans << endl;

  return 0;
}
