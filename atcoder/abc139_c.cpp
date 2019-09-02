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

  int ans = 0;

  int c = 0;
  for(int i = N - 1; i > 0; i--) {
    if(H[i-1] < H[i]) {
      c = 0;
    } else {
      c++;
      ans = max(ans, c);
    }
  }

  cout << ans << endl;

  return 0;
}
