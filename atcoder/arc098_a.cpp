#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
string S;

int main () {
  cin >> N >> S;

  vector<int> W(N+1, 0), E(N+1, 0);

  rep(i,N) {
    char c = S[i];
    W[i+1] = W[i] + (c == 'W');
    E[i+1] = E[i] + (c == 'E');
  }

  int ans = N;
  rep(i,N) {
    ans = min(ans, W[i] + E[N] - E[i+1]);
  }

  cout << ans << endl;

  return 0;
}
