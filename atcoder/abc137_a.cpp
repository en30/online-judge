#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B;
int main () {
  cin >> A >> B;

  cout << max(A+B, max(A-B, A*B)) << endl;
  return 0;
}
