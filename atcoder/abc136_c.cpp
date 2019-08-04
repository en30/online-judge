#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> H;

int main () {
  cin >> N;
  H.resize(N);
  rep(i,N) cin >> H[i];

  bool ok = true;
  int m = H[0];
  rep(i,N) {
    m = max(m, H[i]);
    if(m - H[i] > 1) {
      ok = false;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
