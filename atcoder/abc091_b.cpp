#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, M;

int main () {
  cin >> N;
  map<string, int> c;
  rep(i,N) {
    string s;
    cin >> s;
    c[s]++;
  }

  cin >> M;
  rep(i,M) {
    string s;
    cin >> s;
    c[s]--;
  }

  int ans = 0;
  for(auto p: c) {
    ans = max(ans, p.second);
  }

  cout << ans << endl;

  return 0;
}
