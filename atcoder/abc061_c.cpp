#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int MAX = 100001;
ll d[MAX];

int main () {
  REP(i,MAX) d[i] = 0;

  int n, a, b;
  ll k;
  cin >> n >> k;
  REP(i,n) {
    cin >> a >> b;
    d[a] += b;
  }
  REP(i,MAX) {
    k -= d[i];
    if(k <= 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
