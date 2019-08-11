#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

char X, Y;

int main () {
  cin >> X;
  cin.get();
  cin >> Y;

  if(X == Y) {
    cout << '=';
  } else if(X < Y) {
    cout << '<';
  } else {
    cout << '>';
  }
  cout << endl;

  return 0;
}
