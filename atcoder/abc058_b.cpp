#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string o,e;
  cin >> o >> e;

  int l = e.size();
  rep(i,l) {
    cout << o[i] << e[i];
  }
  if(l != o.size()) cout << o[l];
  cout << endl;
  return 0;
}
