#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int x,a,b;
  cin >> x >> a >> b;
  if(b <= a) {
    cout << "delicious";
  } else if(b <= a + x){
    cout << "safe";
  } else {
    cout << "dangerous";
  }
  cout << endl;
  return 0;
}
