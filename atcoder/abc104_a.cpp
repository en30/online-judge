#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int R;
  cin >> R;
  if(R < 1200) {
    cout << "ABC";
  } else if(R < 2800) {
    cout << "ARC";
  } else {
    cout << "AGC";
  }
  cout << endl;
  return 0;
}
