#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C;

int main () {
  cin >> A >> B >> C;
  cout << ((A+B >= C) ? "Yes" : "No") << endl;
  return 0;
}
