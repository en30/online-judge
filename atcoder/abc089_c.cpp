#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
ll n[5];

map<char, int> m;

int main () {
  string s = "MARCH";

  cin >> N;
  rep(i,N) {
    string S;
    cin >> S;
    rep(i,5) if(S[0] == s[i]) n[i]++;
  }

  ll ans = 0;
  for(int i = 0; i < 5; i++) {
    for(int j = i+1; j < 5; j++) {
      for(int k = j+1; k < 5; k++) {
        ans += n[i]*n[j]*n[k];
      }
    }
  }

  cout << ans << endl;

  return 0;
}
