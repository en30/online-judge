#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  string N;
  cin >> N;
  vector<int> A(4);
  rep(i,4)  A[i] = N[i] - '0';

  rep(s,(1<<3)) {
    int x = A[0];
    rep(i,3) {
      if((s>>i) & 1) {
        x += A[i+1];
      } else {
        x -= A[i+1];
      }
    }
    if(x == 7) {
      cout << A[0];
      rep(i,3) {
        if((s>>i) & 1) {
          cout << '+';
        } else {
          cout << '-';
        }
        cout << A[i+1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
  return 0;
}
