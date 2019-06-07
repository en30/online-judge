#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int vv(int m) {
  if(m < 100) return 0;
  if(m <= 5000) return m/100;
  if(m <= 30000) return (m/1000 + 50);
  if(m <= 70000) return ((m/1000 - 30) / 5 + 80);
  return 89;
}
int main () {
  int m;
  cin >> m;
  printf("%02d\n", vv(m));
  return 0;
}
