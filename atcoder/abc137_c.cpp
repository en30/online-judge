#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<string> s;

int main () {
  cin >> N;
  s.resize(N);

  map<string, ll> m;
  rep(i,N) {
    cin >> s[i];
    sort(all(s[i]));
    m[s[i]] += 1;
  }

  ll ans = 0;
  for(auto kv: m) {
    ans += kv.second*(kv.second-1)/2;
  }

  cout << ans << endl;
  return 0;
}
