#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int N;
  cin >> N;

  vector<ll> L(N+1);
  L[0] = 2;
  L[1] = 1;
  for(int i = 2; i <= N; i++) {
    L[i] = L[i-1] + L[i-2];
  }
  cout << L[N] << endl;
  return 0;
}
