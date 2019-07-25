#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  rep(i,N) {
    cin >> m[i];
    X -= m[i];
  }
  sort(m.begin(), m.end());
  cout << N + (X/m[0]) << endl;
  return 0;
}
