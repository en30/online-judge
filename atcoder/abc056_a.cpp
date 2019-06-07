#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  char a,b;
  cin >> a >> b;
  if((a == 'H' && b == 'H') || (a == 'D' && b == 'D')) {
    cout << 'H' << endl;
  } else {
    cout << 'D' << endl;
  }
  return 0;
}
