#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a,b,c;
  cin >> a >> b >> c;
  cout << (a <= c && c <= b ? "Yes" : "No") << endl;
  return 0;
}
