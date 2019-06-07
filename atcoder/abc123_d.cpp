#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int x, y, z, k;
vector<ll> a, b, c;

struct state {
  int i,j,k;
  ll value() const {
    return a[i] + b[j] + c[k];
  }
  bool operator<(const state& rhs) const {
    return value() < rhs.value();
  }
  bool operator==(const state& rhs) const {
    return i == rhs.i && j == rhs.j && k == rhs.k;
  }
};

namespace std{
    template<>
    class hash<state>{
        public:
        size_t operator () ( const state &s ) const{ return s.i + s.j*1e3 + s.k*1e6; }
    };
}

int main () {
  priority_queue<state> q;
  unordered_map<state, bool> used;

  cin >> x >> y >> z >> k;
  a = vector<ll>(x);
  b = vector<ll>(y);
  c = vector<ll>(z);
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];

  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());

  state s = state{0,0,0};
  q.push(s);
  used[s] = true;

  rep(i,k) {
    s = q.top(); q.pop();
    cout << s.value() << endl;

    state next[3] = { state{s.i+1, s.j, s.k}, state{s.i, s.j+1, s.k}, state{s.i, s.j, s.k+1}};
    if(next[0].i < x && !used[next[0]]) {
      q.push(next[0]);
      used[next[0]] = true;
    }
    if(next[1].j < y && !used[next[1]]) {
      q.push(next[1]);
      used[next[1]] = true;
    }
    if(next[2].k < z && !used[next[2]]) {
      q.push(next[2]);
      used[next[2]] = true;
    }
  }

  return 0;
}
