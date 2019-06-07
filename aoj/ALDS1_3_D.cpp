#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct puddle {
  int area;
  int x;
};

int main () {
  stack<int> down;
  stack<puddle> s;
  char c;
  int x = 0;
  while(cin >> c) {
    x++;
    if(c == '\\') {
      down.push(x);
    } else if(c == '/' && !down.empty()) {
      int px = down.top(); down.pop();
      int a = x - px;
      while(!s.empty() && s.top().x > px) {
        a += s.top().area;
        s.pop();
      }
      s.push(puddle{a, x});
    }
  }

  int A = 0;
  vector<int> L(s.size());
  rep(i,L.size()) {
    int a = s.top().area;
    L[L.size() - 1 - i] = a;
    A += a;
    s.pop();
  }

  cout << A << endl;
  cout << L.size();
  rep(i,L.size()) cout << " " << L[i];
  cout << endl;
  return 0;
}
