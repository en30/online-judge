#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
ll X;
vector<ll> nAll;
vector<ll> nP;

ll f(int l, ll x) {
  if(x == 0) return 0;
  if(l == 0) return x;

  if(x == nAll[l]) return nP[l];
  if(x < nAll[l-1] + 2) return f(l-1, x-1);
  return 1 + nP[l-1] + f(l-1, x - nAll[l-1] - 2);
}

int main () {
  cin >> N >> X;

  nAll = vector<ll>(N+1, 1);
  nP = vector<ll>(N+1, 1);
  rep(i,N) {
    nAll[i+1] = 2*nAll[i] + 3;
    nP[i+1] = 2*nP[i] + 1;
  }

  cout << f(N, X) << endl;
  return 0;
}
