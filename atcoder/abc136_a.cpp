#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C;

int main () {
  cin >> A >> B >> C;

  cout << max(C-(A-B), 0) << endl;
  return 0;
}
