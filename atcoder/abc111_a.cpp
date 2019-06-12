#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  cin >> s;

  for(char c: s) {
    if(c == '1') {
      cout << '9';
    } else {
      cout << '1';
    }
  }
  cout << endl;

  return 0;
}
