#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class BIT {
private:
  int n;
  vector<int> bit;

public:
  BIT(int _n) {
    n = _n;
    bit = vector<int>(n, 0);
  }

  int sum(int i) {
    int s = 0;
    while(i > 0) {
      s += bit[i];
      i -= i & (-i);
  }
    return s;
  }

  void add(int i, int val) {
    while(i <= n) {
      bit[i] += val;
      i += i & (-i);
    }
  }

  ~BIT() {
    vector<int> tv;
    bit.swap(tv);
  }
};

int main () {
  int n, k;
  scanf("%d%d", &n, &k);

  vector<ll> s(n+1);

  s[0] = 0;
  rep(i,n) {
    int a;
    scanf("%d", &a);
    s[i+1] = s[i] + (a - k);
  }

  vector<ll> ss(s);
  sort(ss.begin(), ss.end());

  // map {s} to [1, n+1]
  // BIT operations: O(log(s_max)) -> O(log(n))
  for(int i = 0; i <= n; i++) {
    s[i] = distance(ss.begin(), lower_bound(ss.begin(), ss.end(), s[i])) + 1;
  }

  BIT bit(n+2);
  ll c = 0;
  for(int i = n; i >= 0; i--) {
    c += bit.sum(s[i] - 1);
    bit.add(s[i], 1);
  }

  printf("%lld\n", ll(n)*(n+1)/2 - c);

  return 0;
}
