#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;

  for(int i = n; i < 1000; i++) {
    if(i % 10 == (i/10) % 10 && i % 10 == (i/100) % 10) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
