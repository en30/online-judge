#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, X;
int main () {
  cin >> A >> B >> X;

  cout << ((A + B >= X && X >= A) ? "YES" : "NO") << endl;
  return 0;
}
