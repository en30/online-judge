#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int k = 10000;

template<typename T>
std::ostream& operator<<(std::ostream &strm, const vector<T> &v) {
  for(int i = 0, l = v.size(); i < l; i++) {
    if(i != 0) strm << " ";
    strm << v[i];
  }
  return strm;
}

int main () {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<int> b(n);
  vector<int> c(k, 0);
  rep(i,n) {
    cin >> a[i];
    c[a[i]] += 1;
  }

  for(int i = 1; i < n; i++) c[i] += c[i-1];

  for(int i = n-1; i >= 0; i--) {
    b[c[a[i]]-1] = a[i];
    c[a[i]] -= 1;
  }

  cout << b << endl;

  return 0;
}
