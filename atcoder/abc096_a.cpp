#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int a, b;
  cin >> a >> b;
  cout << (a - 1 + (a <= b)) << endl;
  return 0;
}
