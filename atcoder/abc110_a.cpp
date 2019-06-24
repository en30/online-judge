#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a,b,c;
  cin >> a >> b >> c;

  cout << (a + b + c + (max(a,max(b,c))) * 9) << endl;
  return 0;
}
