#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int N;
  cin >> N;
  vector<int> A(N);

  double x = 1;
  rep(i,N) {
    cin >> A[i];
    x *= A[i];
  }
  double y = 0;
  rep(i,N) y += x / A[i];

  cout << x / y << endl;
  return 0;
}
