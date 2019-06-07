#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

void p(vector<int> &a, vector<int> &b) {
  reverse(a.begin(), a.end());
  rep(i,a.size()) {
    if(i != 0) printf(" ");
    printf("%d", a[i]);
  }
  rep(i,b.size()) {
    printf(" %d", b[i]);
  }
  printf("\n");
}

int main () {
  int n;
  cin >> n;
  vector<int> e((n+1)/2), o(n/2);
  rep(i,n) {
    if(i % 2 == 0) {
      cin >> e[i / 2];
    } else {
      cin >> o[(i-1) / 2];
    }
  }

  if(n % 2 == 0) {
    p(o, e);
  } else {
    p(e, o);
  }

  return 0;
}
