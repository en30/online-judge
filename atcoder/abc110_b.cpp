#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n,m,X,Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  if(x[x.size()-1] < y[0] && y[0] > X && x[x.size()-1] < Y) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }

  return 0;
}
