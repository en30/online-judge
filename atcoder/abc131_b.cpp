#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, L;
  cin >> N >> L;

  int s = 0;
  int m = 1e9;
  int j = 0;
  for(int i = 1; i <= N; i++) {
    int t =  L + i - 1;
    s += t;
    if(abs(t) < m) {
      m = abs(t);
      j = i;
    }
  }

  cout << s - L - j + 1 << endl;

  return 0;
}
