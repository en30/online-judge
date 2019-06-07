#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string s;
  cin >> s;

  int d0 = 0, d1 = 0;
  int i = 0;
  for(char c: s) {
    if(i % 2 == 0) {
      if(c == '0') d1 += 1;
      if(c == '1') d0 += 1;
    } else {
      if(c == '1') d1 += 1;
      if(c == '0') d0 += 1;
    }
    i++;
  }

  cout << min(d0, d1) << endl;

  return 0;
}
