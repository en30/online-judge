#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string W;

  cin >> W;

  for(char c: W) {
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') continue;
    cout << c;
  }
  cout << endl;

  return 0;
}
