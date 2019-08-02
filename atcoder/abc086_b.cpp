#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int a, b;

int main () {
  cin >> a >> b;
  vector<int> s(100101, 0);
  for(int i = 1; i*i < 100100; i++) {
    s[i*i] = 1;
  }

  int i = 1;
  while(b/i != 0) {
    i *= 10;
  }

  cout << (s[a*i + b] ? "Yes" : "No") << endl;
  return 0;
}
