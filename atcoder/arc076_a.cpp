#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int d = 1000000007;
vector<int> memo(100001, -1);
int fact(int i) {
  if(i == 1) return 1;
  if(memo[i] != -1) return memo[i];
  int res = (ll(i) * ll(fact(i-1))) % d;
  memo[i] = res ;
  return res;
}

int main () {
  int n, m;
  cin >> n >> m;

  int ans;
  if((n + m) % 2 == 1) {
    if(abs(n - m) != 1) {
      ans = 0;
    } else {
      ans = ll(fact(m)) * fact(n) % d;
    }
  } else {
    if(n != m) {
      ans = 0;
    } else {
      ans = ll(2) * fact(n) * fact(m) % d;
    }
  }
  printf("%d\n", ans);
  return 0;
}
