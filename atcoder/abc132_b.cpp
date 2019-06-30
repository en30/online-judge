#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;

  vector<int> p(n);
  rep(i,n) cin >> p[i];

  int c = 0;
  for(int i = 1; i < n - 1 ; i++) {
    int r = max(p[i-1], max(p[i], p[i+1]));
    int l = min(p[i-1], min(p[i], p[i+1]));
    if(p[i] != r && p[i] != l) c++;
  }

  cout << c << endl;
  return 0;
}
