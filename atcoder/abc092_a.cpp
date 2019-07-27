#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C, D;
int main () {
  cin >> A >> B >> C >> D;

  cout << min(A,B) + min(C, D) << endl;
  return 0;
}
