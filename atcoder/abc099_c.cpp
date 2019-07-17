#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> v;
int ub;

int f(int n, int rest, int i) {
  if(n > ub) return ub;
  if(rest == 0) return n;
  if(i == v.size()) return 1e9;
  int ans = 1e9;
  for(int j = 0; j*v[i] <= rest; j++) {
    ans = min(ans, f(n+j, rest-j*v[i], i+1));
  }
  return ans;
}

int main () {
  cin >> N;

  v.push_back(1);
  for(int x = 6; x <= N; x *= 6) {
    v.push_back(x);
  }
  for(int x = 9; x <= N; x *= 9) {
    v.push_back(x);
  }
  sort(v.begin(), v.end());

  ub = 0;
  int m = N;
  while(m > 0) {
    int i = distance(v.begin(), upper_bound(v.begin(), v.end(), m)) - 1;
    m -= v[i];
    ub++;
  }

  cout << f(0, N, 0) << endl;

  return 0;
}
