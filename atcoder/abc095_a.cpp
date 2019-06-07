#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  char c;
  int p = 700;
  rep(i,3){
    cin >> c;
    if(c == 'o') p += 100;
  }
  cout << p << endl;
  return 0;
}
