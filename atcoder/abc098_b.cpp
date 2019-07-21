#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
string S;

int main () {
  cin >> N >> S;

  int ans = 0;
  for(int i = 1; i < N - 1; i++) {
    set<char> x, y, z;
    for(int j = 0; j < N; j++) {
      if(j < i) {
        x.insert(S[j]);
      } else {
        y.insert(S[j]);
      }
    }
    set_intersection(x.begin(), x.end(), y.begin(), y.end(), inserter(z, z.end()));
    ans = max(ans, (int)z.size());
  }

  cout << ans << endl;

  return 0;
}
