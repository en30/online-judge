#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int A, B, K;

  cin >> A >> B >> K;

  int c = 0;

  for(int i = min(A, B); i > 0; i--) {
    if(A % i == 0 && B % i == 0) {
      c++;
      if(c >= K) {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}
