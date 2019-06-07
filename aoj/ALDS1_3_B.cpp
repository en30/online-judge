#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct process {
  string name;
  int time;
};

int main () {
  int n, q;
  int res = 0;

  cin >> n >> q;
  queue<process> que;
  string s;
  int t;
  while(cin >> s >> t) {
    que.push(process{s, t});
  }

  while(!que.empty()) {
    process p = que.front(); que.pop();
    if(p.time > q) {
      p.time -= q;
      res += q;
      que.push(p);
    } else {
      res += p.time;
      cout << p.name << " " << res << endl;
    }
  }

  return 0;
}
