#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);

  int m = 0;

  rep(i,N) {
    cin >> X[i] >> Y[i];
    m = max(m, abs(X[i])+ abs(Y[i]));
  }

  int p = (X[0] + Y[0]) & 1;
  rep(i,N) {
    if(((X[i] + Y[i]) & 1) != p) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << m << endl;
  rep(i,m) {
    if(i != 0) cout << " ";
    cout << 1;
  }
  cout << endl;

  rep(i,N) {
    rep(j, abs(X[i])) cout << (X[i] > 0 ? 'R' : 'L');
    rep(j, abs(Y[i])) cout << (Y[i] > 0 ? 'U' : 'D');

    rep(j,(m-abs(X[i])-abs(Y[i]))/2) cout << "RL";
    cout << endl;
  }

  return 0;
}
