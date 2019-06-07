#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int y,m,d;

  scanf("%d/%d/%d", &y, &m, &d);

  if(y > 2019 || (y == 2019 && m > 4)) {
    cout << "TBD" << endl;
  } else {
    cout << "Heisei" << endl;
  }

  return 0;
}
