#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  cin >> s;
  int l = s.size();
  printf("%c%d%c\n", s[0], l-2, s[l-1]);
  return 0;
}
