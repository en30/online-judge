#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());

  int l = -1;
  int r = n;
  while(r - l > 1) {
    int i = (l + r) / 2;

    if(k - a[i] <= 0) {
      r = i;
      continue;
    }

    vector<int> can(k,0);
    can[0] = 1;

    for(int j = 0; j < n; j++) {
      if(j == i) continue;
      for(int l = k - 1; l >= 0; l--) {
        if(can[l] && l + a[j] < k) can[l+a[j]] = 1;
      }
    }

    bool nec = false;
    for(int j = k - a[i]; j < k; j++) {
      if(can[j]) nec = true;
    }
    if(nec) {
      r = i;
    } else {
      l = i;
    }
  }

  cout << r << endl;
  return 0;
}
