#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B;

int main () {
  cin >> A >> B;

  int M = (A+B)/2;
  if(abs(A-M) == abs(B-M)) {
    cout << M << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
