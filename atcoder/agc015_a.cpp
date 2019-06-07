#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

ll n,a,b;
int main () {
  cin >> n >> a >> b;
  if(b < a || (n == 1 && a != b)) {
    cout << 0 << endl;
  } else {
    cout << (n - 2) * (b - a) + 1 << endl;
  }
  return 0;
}
