#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int a, b;

int main () {
  cin >> a >> b;
  int n = b - a ;
  cout << n*(n+1)/2 - b << endl;
  return 0;
}
