#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int H, W, D, Q;

int main () {
  cin >> H >> W >> D;
  int N = H*W;

  vector<int> x(N), y(N);
  rep(i,H) rep(j,W) {
    int A;
    cin >> A;
    A--;
    x[A] = i;
    y[A] = j;
  }

  vector<int> S(N + 1, 0);
  for(int i = D; i < N; i++) {
    S[i] = S[i-D] + abs(x[i] - x[i-D]) + abs(y[i] - y[i-D]);
  }

  cin >> Q;
  while(Q--) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    cout << S[R] - S[L] << endl;
  }

  return 0;
}
