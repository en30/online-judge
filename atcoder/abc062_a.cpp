#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int group(int i) {
  if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) return 0;
  if(i == 4 || i == 6 || i == 9 || i == 11) return 1;
  if(i == 2) return 3;
}
int main () {
  int x, y;
  cin >> x >> y;
  cout << (group(x) == group(y) ? "Yes" : "No") << endl;
  return 0;
}
