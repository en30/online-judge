#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int a;
string s;

int main () {
  cin >> a >> s;
  if(a >= 3200) {
    cout << s << endl;
  } else {
    cout << "red" << endl;
  }
  return 0;
}
