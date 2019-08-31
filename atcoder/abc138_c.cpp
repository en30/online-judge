#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<double> v;

int main () {
  cin >> N;
  v.resize(N);
  rep(i,N) cin >> v[i];

  sort(all(v));

  double x = 0;
  ll k = 1;
  for(int i = N - 1; i >= 1; i--) {
    k *= 2;
    x += v[i] / k;
  }
  x += v[0] / k;

  cout << x << endl;

  return 0;
}
