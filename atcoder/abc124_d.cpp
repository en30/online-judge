#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct item {
  int zero, sum;
};

int main () {
  int n, k;
  string s;

  cin >> n >> k >> s;

  vector<item> a;
  // 1(01)(01)...(01)
  if(s[0] == '0') a.push_back(item{0,0});
  for(int i = 0, l = s.size(); i < l; ) {
    item it = item{0,0};
    while(i < l && s[i] == '0') {
      it.zero++;
      i++;
    }
    it.sum += it.zero;
    while(i < l && s[i] == '1') {
      it.sum++;
      i++;
    }
    a.push_back(it);
  }

  int sum = a[0].sum;
  int ans = sum;
  for(int i = 1; i < a.size(); i++) {
    sum += a[i].sum;
    if(i > k) sum -= a[i-k].zero + (a[i-k-1].sum - a[i-k-1].zero);
    ans = max(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
