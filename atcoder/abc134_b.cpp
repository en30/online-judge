#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, D;
int main () {
  cin >> N >> D;

  int r = (2*D+1);
  cout << (N+r-1)/r << endl;
  return 0;
}
