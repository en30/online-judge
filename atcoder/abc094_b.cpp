#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, M, X;

int main () {
  cin >> N >> M >> X;
  vector<int> A(M);
  rep(i,M) cin >> A[i];

  int a = 0, b = 0;
  rep(i,M) {
    if(A[i] > X) {
      a++;
    } else {
      b++;
    }
  }
  cout << min(a, b) << endl;
  return 0;
}
