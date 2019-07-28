#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int N;
  cin >> N;
  vector<int> p(N), q(N);
  rep(i,N) {
    cin >> p[i];
    q[i] = p[i];
  }

  sort(all(q));

  int c = 0;
  rep(i,N) {
    if(p[i] != q[i]) c++;
  }

  cout << (c == 0 || c == 2 ? "YES" : "NO") << endl;

  return 0;
}
