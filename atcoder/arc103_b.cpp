#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

typedef pair<int, int> sig;

int main () {
  map<sig, char> dir;
  dir[sig(+1, +1)] = 'R';
  dir[sig(+1, -1)] = 'U';
  dir[sig(-1, +1)] = 'D';
  dir[sig(-1, -1)] = 'L';

  int N;
  cin >> N;
  vector<int> U(N), V(N);

  rep(i,N) {
    int X, Y;
    cin >> X >> Y;
    U[i] = X + Y;
    V[i] = X - Y;
  }

  int p = U[0] & 1;
  rep(i,N) {
    if((U[i] & 1) != p) {
      cout << "-1" << endl;
      return 0;
    }
  }


  int m = 31;
  cout << m + (!p) << endl;
  if(!p) cout << "1 ";
  for(int i = m - 1; i >= 0; i--) {
    cout << (1<<i);
    if(i != 0) cout << " ";
  }
  cout << endl;

  rep(i,N) {
    int u = 0, v = 0;
    if(!p) {
      cout << 'R';
      u++; v++;
    }

    for(int j = m - 1; j >= 0; j--) {
      int d = (1<<j);

      sig s = sig((U[i]-u)/abs(U[i] - u), (V[i] - v)/abs(V[i] - v));
      u += d*s.first;
      v += d*s.second;
      cout << dir[s];
    }
    cout << endl;
  }

  return 0;
}
