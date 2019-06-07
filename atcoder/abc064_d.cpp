#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int l = 0;
  string s;
  int n;
  cin >> n >> s;

  int i = 0, j = 0;
  rep(i,n) {
    if(s[i] == '(') {
      j++;
    } else {
      j--;
    }
    l = max(l, -j);
  }

  rep(i, l) printf("(");
  cout << s;
  rep(i, l+j) printf(")");
  printf("\n");
  return 0;
}
