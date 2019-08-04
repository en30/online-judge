#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

bool odd(int n) {
  if(n / 10 == 0) return 1;
  return (1 + odd(n/10))%2;
}

int main () {
  cin >> N;

  int ans = 0;
  for(int i = 1; i <= N; i++) ans += odd(i);
  cout << ans << endl;
  return 0;
}
