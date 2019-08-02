#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

int main () {
  cin >> N;
  map<int, int> c;
  rep(i,N){
    int a;
    cin >> a;
    c[a]++;
  }

  ll ans = 0;
  for(auto p: c) {
    ans += p.second >= p.first ? (p.second - p.first) : p.second;
  }
  cout << ans << endl;

  return 0;
}
