#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

char upcase(char &c) {
  return toupper((unsigned char) c);
};

int main () {
  string a,b,c;
  cin >> a >> b >> c;
  cout << upcase(a[0]) << upcase(b[0]) << upcase(c[0]) << endl;
  return 0;
}
