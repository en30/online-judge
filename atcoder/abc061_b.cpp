#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int res[50];

int main () {
  int n, m, a, b;
  cin >> n >> m;
  REP(i,n) res[i] = 0;
  REP(i,m) {
    cin >> a >> b;
    res[a-1]++;
    res[b-1]++;
  }
  REP(i,n) cout << res[i] << endl;
  return 0;
}
