#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string s;
int X, Y;

const int R_MAX = 8000;

int main () {
  cin >> s >> X >> Y;
  vector<set<int>> sr(2);

  int x0 = 0;
  while(s[x0] == 'F') x0++;
  sr[0].insert(x0);
  sr[1].insert(0);

  for(int i = x0+1, dir = 1; i < s.size(); i++, dir ^= 1) {
    int d = 0;
    while(s[i] == 'F') {
      i++;
      d++;
    }
    set<int> s;
    for(int r: sr[dir]) {
      s.insert(r+d);
      s.insert(r-d);
    }
    sr[dir] = s;
  }

  if(sr[0].find(X) != sr[0].end() && sr[1].find(Y) != sr[1].end()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
