#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string s, t;
unordered_map<char, set<int>> h;

int main () {
  cin >> s >> t;

  int N = s.size(), M = t.size();
  rep(i,N) h[s[i]].insert(i);

  int k = 0;
  ll ans = 0;
  rep(i,M) {
    char c = t[i];
    auto it = h[c].lower_bound(k);
    if(it == h[c].end()) {
      it = h[c].lower_bound(0);
      ans += N;
    }

    if(it == h[c].end()) {
      cout << "-1" << endl;
      return 0;
    }

    k = (*it) + 1;
  }

  ans += k;
  cout << ans << endl;


  return 0;
}
