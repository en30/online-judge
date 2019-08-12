#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> a;

struct op {
  int x, y;
};

int main () {
  cin >> N;
  a.resize(N);
  rep(i,N) cin >> a[i];

  vector<op> ans;

  int iMax = distance(a.begin(), max_element(all(a)));
  int iMin = distance(a.begin(), min_element(all(a)));

  bool right = (iMin >= 0);
  if(abs(a[iMax]) > abs(a[iMin])) {
    rep(i,N) if(a[i] < 0) {
      ans.push_back(op{iMax, i});
    }
    right = true;
  } else {
    rep(i,N) if(a[i] > 0) {
      ans.push_back(op{iMin, i});
    }
    right = false;
  }

  rep(i,N-1) {
    if(right) {
      ans.push_back(op{i, i+1});
    } else {
      ans.push_back(op{N-1-i, N-2-i});
    }
  }

  cout << ans.size() << endl;
  for(auto &e: ans) {
    cout << (e.x+1) << " " << (e.y+1) << endl;
  }

  return 0;
}
