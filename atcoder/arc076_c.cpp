#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int r,c,n;

class P {
public:
  int x,y;
  bool onEdge() {
    return y == 0 || y == c || x == 0 || x == r;
  }
  int d() {
    if(y == 0) {
      return x;
    } else if(x == r) {
      return r+y;
    } else if(y == c) {
      return 2*r + c - x;
    } else if(x == 0) {
      return 2*r + 2*c - y;
    }
  }
};

int main () {
  priority_queue<pair<int, int>> q;

  scanf("%d %d %d", &r, &c, &n);
  rep(i,n) {
    P p1, p2;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    if(p1.onEdge() && p2.onEdge()) {
      q.push(make_pair(p1.d(), i));
      q.push(make_pair(p2.d(), i));
    }
  }

  stack<int> s;
  while(!q.empty()) {
    int i = q.top().second; q.pop();
    if(s.empty()) {
      s.push(i);
    } else if(s.top() == i) {
      s.pop();
    } else {
      s.push(i);
    }
  }

  if(s.empty()){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
