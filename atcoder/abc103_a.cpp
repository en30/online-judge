#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a1,a2,a3;
  cin >> a1 >> a2 >> a3;

  cout << min(abs(a1-a2) + abs(a2-a3), min(abs(a1-a3) + abs(a3-a2), abs(a1-a2) + abs(a1-a3))) << endl;
  return 0;
}
