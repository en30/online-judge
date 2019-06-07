#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a,b;
  cin >> a >> b;
  if(a + b >= 10) {
    cout << "error";
  } else {
    cout << a + b;
  }
  cout << endl;
  return 0;
}
