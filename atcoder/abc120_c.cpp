#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  int a = 0, b = 0;

  cin >> s;
  for(char c: s) {
    if(c == '0') {
      a++;
    } else {
      b++;
    }
  }

  cout << min(a,b) * 2 << endl;

  return 0;
}
