#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s, t;
  cin >> s >> t;

  const int R = 50;
  vector<int> sc(R, 0), tc(R, 0);

  int n = s.size();
  for(char c: s) sc[c - 'a'] += 1;
  for(char c: t) tc[c - 'a'] += 1;

  sort(sc.begin(), sc.end());
  sort(tc.begin(), tc.end());

  rep(i,R) if(sc[i] != tc[i]) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  return 0;
}
