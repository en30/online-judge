#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  vector<int> p(3);
  cin >> p[0] >> p[1] >> p[2];

  sort(p.begin(), p.end());
  cout << p[0] + p[1] << endl;

  return 0;
}
