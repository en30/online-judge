#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string S;
  ll K;

  cin >> S >> K;

  for(char c: S) {
    if(c != '1') {
      cout << c << endl;
      return 0;
    } else {
      K--;
      if(K == 0) break;
    }
  }

  cout << '1' << endl;

  return 0;
}
