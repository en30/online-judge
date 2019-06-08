#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int n;
int ans;

void dfs(ll i, int used) {
  if(i > n) return;
  if(((used & 0b111) == 0b111)) ans++;

  dfs(i*10 + 3, used | 1);
  dfs(i*10 + 5, used | (1<<1));
  dfs(i*10 + 7, used | (1<<2));
}

int main () {
  cin >> n;
  ans = 0;

  dfs(0, 0);

  cout << ans << endl;

  return 0;
}
