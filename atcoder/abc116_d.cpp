#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

template <class T>
using minpq = std::priority_queue<T, vector<T>, greater<T>>;

template <class T>
using maxpq = std::priority_queue<T, vector<T>, less<T>>;

struct sushi {
  int d, t;
};

int main () {
  int k, n;
  cin >> n >> k;
  vector<sushi> s(n);
  vector<int> usedT(n+1, 0);
  rep(i,n) {
    cin >> s[i].t >> s[i].d;
  }

  sort(s.begin(), s.end(), [](const sushi &a, const sushi &b){
      return a.d > b.d;
    });
  ll ans = 0;
  ll tc = 0;
  maxpq<ll> q;
  minpq<int> surplus;
  rep(i,k) {
    ans += s[i].d;
    if(usedT[s[i].t]) {
      surplus.push(s[i].d);
    } else {
      usedT[s[i].t] = 1;
      ans += 2*tc + 1;
      tc++;
    }
  }
  q.push(ans);

  for(int i = k; i < n; i++) {
    if(surplus.size() == 0) break;
    if(usedT[s[i].t]) continue;
    ans += s[i].d - surplus.top() + 2*tc + 1;
    tc++;
    surplus.pop();
    q.push(ans);
    usedT[s[i].t] = 1;
  }

  cout << q.top() << endl;

  return 0;
}
